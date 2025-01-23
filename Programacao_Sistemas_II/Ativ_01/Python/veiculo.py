class Veiculo:
    """Representação da classe pai Veiculo"""
    def __init__(self, marca, modelo, combustivel, cor, ano):
        """Método construtor da classe Veiculo

        Arguments:
            marca -- string que representa o nome da marca do veículo
            modelo -- string que representa o modelo do veículo
            combustivel -- string que representa o combustível aceito pelo veículo
            cor -- string que representa a cor do veículo
            ano -- inteiro que representa o ano do veículo
        """
        self.marca = marca
        self.modelo = modelo
        self.combustivel = combustivel
        self.cor = cor
        self.ano = ano

    # Métodos getters
    def get_marca(self):
        return self.marca

    def get_modelo(self):
        return self.modelo

    def get_combustivel(self):
        return self.combustivel

    def get_cor(self):
        return self.cor

    def get_ano(self):
        return self.ano

    def exibir_detalhes(self):
        """Método para exibir os detalhes do veículo

        Returns:
            Uma string formatada com os dados do veículo
        """
        detalhes = (f"Marca: {self.marca}\nModelo: {self.modelo}\nCombustível: {self.combustivel}\nCor: {self.cor}\n"
                    f"Ano: {self.ano}")

        return detalhes


class Carro(Veiculo):
    """Representação da subclasse Carro"""
    def __init__(self, marca, modelo, combustivel, cor, ano, portas):
        """Método construtor da subclasse Carro

        Arguments:
            portas -- inteiro que representa o número de portas do carro
        """
        super().__init__(marca, modelo, combustivel, cor, ano)
        self.portas = portas

    def get_portas(self):
        return self.portas

    def exibir_detalhes(self):
        """Método para exibir os detalhes do carro"""
        detalhes_veiculo = super().exibir_detalhes()
        detalhes_carro = f"{detalhes_veiculo}\nPortas: {self.portas}"

        return detalhes_carro


class Motocicleta(Veiculo):
    """Representação da subclasse Motocicleta"""
    def __init__(self, marca, modelo, combustivel, cor, ano, side_car):
        """Método construtor da subclasse Motocicleta

        Arguments:
            side_car -- boolean que representa a presença de side car na motocicleta
        """
        super().__init__(marca, modelo, combustivel, cor, ano)
        self.side_car = side_car

    def get_side_car(self):
        return self.side_car

    def exibir_detalhes(self):
        """Método para exibir os detalhes da motocicleta"""
        detalhes_veiculo = super().exibir_detalhes()
        detalhes_motocicleta = f"{detalhes_veiculo}\nSide Car: {self.side_car}"

        return detalhes_motocicleta


# Exemplos de uso
carro = Carro("Fiat", "Elba CS 1.5", "Álcool","Branco", 1991, 4)
print(carro.exibir_detalhes())
print()
motocicleta = Motocicleta("Honda", "CBR 750F", "Gasolina", "Vermelho", 1992, False)
print(motocicleta.exibir_detalhes())
