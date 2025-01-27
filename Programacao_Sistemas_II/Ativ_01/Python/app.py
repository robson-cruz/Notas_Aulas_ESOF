import logging
from flask import render_template, url_for, flash, redirect, request
from flask_login import login_user, current_user, login_required, logout_user
from werkzeug.security import check_password_hash, generate_password_hash
from models.forms import UserForm, LoginForm, CarForm, MotorcycleForm
from config import app, db, login_manager
from models.models import User, Motorcycle, Car


@login_manager.user_loader
def load_user(user_id):
    return db.get_or_404(User, user_id)


@app.route("/")
def home():
    motos = db.session.query(Motorcycle).all()
    cars = db.session.query(Car).all()

    return render_template(
        "index.html",
        title="Home",
        current_user=current_user,
        tables=[motos, cars]
    )


# Register new users into the User database
@app.route("/cadastrar-usuario", methods=["GET", "POST"])
def sign_up():
    form = UserForm()
    if form.validate_on_submit():
        # Check if the user email is already present in the database
        result = db.session.execute(db.select(User).where(User.email == form.email.data))
        user = result.scalar()
        if user:
            flash("Usuário já cadastrado com este email.", "warning")
            return redirect(url_for('login'))

        # Hash the password
        hash_and_salted_password = generate_password_hash(
            form.password.data,
            method="pbkdf2:sha256",
            salt_length=16
        )

        # Create a new user
        new_user = User(
            name=form.name.data,
            email=form.email.data,
            password=hash_and_salted_password
        )

        # Add the new user to the database with error handling
        try:
            db.session.add(new_user)
            db.session.commit()
        except Exception as e:
            db.session.rollback()  # Rollback the transaction
            logging.error(f"Erro ao cadastrar usuário: {e}")
            flash("Erro ao cadastrar usuário. Por favor, tente novamente.", "danger")
            return redirect(url_for("sign_up"))

        # Redirect to log in with a success message
        flash("Usuário cadastrado com sucesso! Faça login para continuar.", "success")
        return redirect(url_for("login", title="Login"))

    return render_template("sign_up.html",
                           form=form,
                           title="Cadastrar Usuário",
                           current_user=current_user)


@app.route("/login", methods=["GET", "POST"])
def login():
    if current_user.is_authenticated:
        flash("Você já está logado!", "info")
        return redirect(url_for("home", title="Home"))

    form = LoginForm()  # Create a new instance of the LoginForm class
    if form.validate_on_submit():
        password_form = form.password.data
        result = db.session.execute(db.select(User).where(User.email == form.email.data))
        user = result.scalar()  # email in database is unique so will only have one result

        # Email does not exist in database
        if not user:
            flash("Email não encontrado. Por favor, cadastre-se primeiro.", "danger")
            return redirect(url_for('login'))
        # Password incorrect
        elif not check_password_hash(user.password, password_form):
            flash("Senha inválida!", "danger")
            return redirect(url_for('login'))
        else:
            login_user(user)
            flash("Login realizado com sucesso!", "success")
            next_page = request.args.get('next')
            return redirect(next_page) if next_page else redirect(url_for('home'))

    return render_template("login.html",
                           title="Login",
                           form=form,
                           current_user=current_user)


@app.route("/logout")
@login_required
def logout():
    logout_user()
    flash("Você saiu da sua conta.", "info")
    return redirect(url_for("home", title="Home"))


@app.route("/cadastrar-moto", methods=["GET", "POST"])
@login_required
def create_motorcycle():
    form = MotorcycleForm()
    if form.validate_on_submit():
        new_motorcycle = Motorcycle(
            marca=form.marca.data,
            modelo=form.modelo.data,
            combustivel=form.combustivel.data,
            cor=form.cor.data,
            ano=form.ano.data,
            side_car=form.side_car.data
        )
        # Try to add the new_motorcycle in the database
        try:
            db.session.add(new_motorcycle)
            db.session.commit()
            flash("Moto cadastrada com sucesso!", "success")
            return redirect(url_for('create_motorcycle'))
        except Exception as e:
            db.session.rollback()
            logging.error(f"Erro ao cadastrar moto: {e}")
            flash("Erro ao cadastrar moto. Por favor, tente novamente.", "danger")
            return redirect(url_for('create_motorcycle'))
    return render_template("create.html",
                           title="Cadastrar Moto",
                           btn_name="Cadastrar Moto",
                           form=form,
                           url="create_motorcycle",
                           current_user=current_user)


@app.route("/atualizar-moto/<int:moto_id>", methods=["GET", "POST"])
@login_required
def update_moto(moto_id):
    moto = db.session.get(Motorcycle, moto_id)
    if not moto:
        flash("Moto não encontrada.", "danger")
        return redirect(url_for("home"))

    form = MotorcycleForm(obj=moto)  # Fill the form with the current motorcycle data
    form.button.label.text = "Atualizar Moto"  # Updates the label of the button
    if form.validate_on_submit():
        form.populate_obj(obj=moto)  # Updates the moto object with the form data
        try:
            db.session.commit()
            flash("Moto atualizada com sucesso!", "success")
            return redirect(url_for("home"))
        except Exception as e:
            db.session.rollback()
            logging.error(f"Erro ao atualizar moto (ID {moto_id}): {e}")
            flash("Erro ao atualizar moto. Por favor, tente novamente.", "danger")
    return render_template(
        "update_moto.html",
        form=form,
        title="Atualizar Moto",
        moto=moto
    )


# TODO: delete moto
@app.route("/deletar-moto")
@login_required
def delete_moto(car_id):
    pass


# TODO: add car
@app.route("/cadastrar-carro", methods=["GET", "POST"])
@login_required
def create_car():
    form = CarForm()
    if form.validate_on_submit():
        new_car = Car(
            marca=form.marca.data,
            modelo=form.modelo.data,
            combustivel=form.combustivel.data,
            cor=form.cor.data,
            portas=form.portas.data,
            ano=form.ano.data
        )
        try:
            db.session.add(new_car)
            db.session.commit()
            flash("Carro cadastrado com sucesso!", "success")
            return redirect(url_for('create_car'))
        except Exception as e:
            db.session.rollback()
            logging.error(f"Erro ao cadastrar carro: {e}")
            flash("Erro ao cadastrar carro. Por favor, tente novamente.", "danger")
            return redirect(url_for('create_car'))

    return render_template("create.html",
                           title="Cadastrar Carro",
                           btn_name="Cadastrar Carro",
                           form=form,
                           url="create_car",
                           current_user=current_user)


# TODO: update car
@app.route("/atualizar-carro/<int:car_id>", methods=["GET", "POST"])
@login_required
def update_car(car_id):
    car = db.session.get(Car, car_id)
    if not car:
        flash("Carro não encontrado", "danger")
        return redirect(url_for("home"))

    form = CarForm(obj=car)
    form.button.label = "Atualizar Carro"

    if form.validate_on_submit():
        form.populate_obj(obj=car)
        try:
            db.session.commit()
            flash("Carro atualizada com sucesso!", "success")
            return redirect(url_for("home"))
        except Exception as e:
            db.session.rollback()
            logging.error(f"Erro ao atualizar carro (ID {car_id}): {e}")
            flash("Erro ao atualizar moto. Por favor, tente novamente.", "danger")

    return render_template(
        "update_car.html",
        form=form,
        title="Atualizar Carro",
        car=car
    )


# TODO: delete car
@app.route("/deletar-carro")
@login_required
def delete_car(car_id):
    pass


# Handling the 404 Page Not Found
@app.errorhandler(404)
def handle_404_error(e):
    return render_template("404.html", e=e), 404


# Register the functions to handle HTTP errors
app.register_error_handler(404, handle_404_error)


# TODO: Build the page template to Handling the 500 Internal Server Error
@app.errorhandler(500)
def internal_server_error(e):
    # note that we set the 500 status explicitly
    return render_template('500.html'), 500


if __name__ == "__main__":
    app.run(debug=True)
