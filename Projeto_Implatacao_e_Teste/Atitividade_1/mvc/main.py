from flask import Flask, render_template, request, redirect
from controle import TaskModel


app = Flask(__name__)
task_model = TaskModel()


@app.route('/')
def home():
    tasks_with_indices = [(index, task) for index, task in enumerate(task_model.tasks)]
    return render_template('index.html', tasks=tasks_with_indices)


@app.route('/add', methods=['POST'])
def add_task():
    new_task = request.form.get('new_task')
    if new_task:
        task_model.add_task(new_task)
    return redirect('/')


@app.route('/complete/<int:index>')
def complete_task(index):
    task_model.mark_completed(index)
    return redirect('/')


@app.route('/remove/<int:index>')
def remove_task(index):
    task_model.remove_task(index)
    return redirect('/')


if __name__ == '__main__':
    app.run()
