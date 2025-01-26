# Construção de Estrutura de Classes com Herança em Java

Objetivo:
Desenvolver uma estrutura de classes em Java utilizando o conceito de herança. O exercício planeja praticar a criação de uma hierarquia de classes, onde uma classe pai (superclasse) compartilha atributos e métodos comuns com suas subclasses (classes filhas).

Descrição da Atividade:
Você deverá criar uma estrutura de classes que represente diferentes tipos de veículos. Especificamente, crie uma classe pai chamada Veiculo e duas classes filhas chamadas Carro e Moto. A classe Veiculo deve conter atributos e métodos comuns a todos os veículos, enquanto as classes Carro e Moto devem herdar essas características e incluir atributos ou métodos específicos.

Instruções:
Classe Pai: Veículo
Atributos:
- _String marca_: representa a marca do veículo.
- _String modelo_: representa o modelo do veículo.
- _int ano_: representa o ano de fabricação do veículo.
Métodos:
- _void exibirDetalhes()_: Método para exibir detalhes do veículo.
- _Construtor_ que inicializa os atributos marca, modelo, e ano.

Classe Filha: Carro
Atributos Específicos:
- _int numeroDePortas_: representa o número de portas do carro.
Métodos Específicos:
- _void exibirDetalhes()_: Método sobrescrito para incluir a exibição do número de portas.
- _Construtor_ que inicializa os atributos da classe pai e o atributo numeroDePortas.

Classe Filha: Moto
Atributos Específicos:
- _boolean temSidecar_: indica se a moto possui um sidecar.
Métodos Específicos:
- _void exibirDetalhes()_: Método sobrescrito para incluir a exibição da presença de sidecar.
- _Construtor_ que inicializa os atributos da classe pai e o atributo temSidecar.

Nesta atividade você deve: 
1. Implementar as classes Veiculo, Carro e Moto conforme descrito.
2. Criar uma classe principal (Main) para instanciar objetos de Carro e Moto e demonstrar o funcionamento dos métodos, especialmente o método exibirDetalhes().

> [!TIP]
Dicas para realizar a atividade:
1. Durante as aulas, o professor fornecerá dicas que podem ser utilizadas para a confecção das suas atividades, assim, é de suma importância participar das aulas ao vivo ou assisti-las posteriormente.
2. Assista às aulas conceituais da disciplina.
