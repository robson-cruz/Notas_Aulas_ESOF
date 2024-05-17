USE mae_bebe;

INSERT INTO estado (nome, uf)
VALUES
-- Sudeste
('Espírito Santo', 'ES'),('Minas Gerais', 'MG'),('Rio de Janeiro', 'RJ'),('São Paulo', 'SP'),
-- Sul
('Paraná', 'PR'),('Santa Catarina', 'SC'),('Rio Grande do Sul', 'RS'),
-- Nordeste
('Alagoas', 'AL'),('Bahia', 'BA'),('Ceará', 'CE'),('Maranhão', 'MA'),('Paraíba', 'PB'),
('Pernambuco', 'PE'),('Piauí', 'PI'),('Rio Grande do Norte', 'RN'),('Sergipe', 'SE'),
-- Norte
('Amazonas', 'AM'),('Pará', 'PA'),('Acre', 'AC'),('Roraima', 'RR'),('Rondônia', 'RO'),
('Amapá', 'AP'),('Tocantins', 'TO'),
-- Centro Oeste
('Goiás', 'GO'),('Mato Grosso', 'MT'),('Mato Grosso do Sul', 'MS'),('Distrito Federal', 'DF');


INSERT INTO cidade (nome, id_estado)
VALUES
('Vitória', 1),('Vila Velha', 1),('Cariacica', 1),('Cachoeiro do Itapemirim', 1),
('Linhares', 1),('São Mateus', 1),('Guarapari', 1),('Colatina', 1),('Aracruz', 1),
('Belo Horizonte', 2),('Uberlândia', 2),('Uberaba', 2),('Betim', 2),('Montes Claros', 2),
('Juiz de Fora', 2),('Contagem', 2),
('Niterói', 3),('Rio de Janeiro', 3),('São Gonçalo', 3),('Duque de Caxias', 3),
('Nova Iguaçu', 3),('Niterói', 3),('Belford Roxo', 3),
('São Paulo', 4),('Guarulhos', 4),('Campinas', 4),('São Bernardo do Camp', 4),('Santo André', 4),
('Sorocaba', 4),('Ribeirão Preto', 4),
('Curitiba', 5),('Londrina', 5),('Maringá', 5),('Ponta Grossa', 5),('Cascavel', 5),
('São José dos Pinhais', 5),('Foz do Iguaçu', 5),('Colombo', 5),
('Florianópolis', 6),('Joinville', 6),('Blumenau', 6),('Chapecó', 6),('Itajaí ', 6),
('Palhoça', 6),('Criciúma', 6),('São José', 6),('Lages', 6),
('Porto Alegre', 7),('Canoas', 7),('Gravataí', 7),('Erechim', 7),('Passo Fundo', 7),
('Caxias do Sul', 7),
('Maceió', 8),('Arapiraca', 8),('Rio Largo', 8),('Penedo', 8),('União dos Palmares', 8),
('Salvador', 9),('Feira de Santana', 9),('Vitória da Conquista', 9),('Itabuna', 9),
('Camaçari', 9),('Porto Seguro', 9),('Texeira de Freitas', 9),
('Fortaleza', 10),('Caucaia', 10),('Juazeiro do Norte', 10),('Maracanaú', 10),('Sobral', 10),
('Itapipoca', 10),('Crato', 10),('Maranguape', 10),('Iguatu', 10),
('São Luis', 11),('Imperatriz', 11),('Balsas', 11),('Açailândia', 11),('Santo Antônio dos Lopes', 11),
('Campina Grande', 12),('Queimadas', 12),('Alagoa Grande', 12),('Campina Grande', 12),('Pombal', 12),
('Recife', 13),('Jaboatão dos Guararape', 13),('Olinda', 13),('Petrolina', 13),('Caruaru', 13), 
('Teresina', 14),('Parnaíba', 14),('Picos', 14),('Pirpiri', 14),
('Natal', 15),('São Gonçalo do Amarante', 15),('Parnamirim', 15),('Mossoró', 15),
('Aracaju', 16),('Poço Redondo', 16),('Tobias Barreto', 16),('Lagarto', 16),
('Manaus', 17),('Coari', 17),('Itacoatiara', 17),('Manacapuru', 17),('Parintins', 17),
('Belém', 18),('Santarém', 18),('Marabá', 18),('Paragominas', 18),('Redenção', 18),
('Rio Branco', 19),('Cruzeiro do Sul', 19),('Tarauacá', 19),
('Boa Vista', 20),('Pacaraima', 20),('Caracaraí', 20),
('Porto Velho', 21),('Ji-Paraná', 21),('Ariquemes', 21),
('Macapá', 22),('Santana', 22),('Laranjal do Jari', 22),('Oiapoque', 22),
('Palmas', 23),('Araguaína', 23),('Porto Nacional', 23),('Gurupi', 23),
('Goiânia', 24),('Anápolis', 24),('Catalão', 24),('Aparecida de Goiânia', 24),
('Cuiabá', 25),('Várzea Grande', 25),('Rondonópolis', 25),('Sinop', 25),('Sorriso', 25),
('Campo Grande', 26),('Dourados', 26),('Três Lagoas', 26),
('Brasília', 27),('Ceilândia', 27),('Samambaia', 27),('Taguatinga', 27);

INSERT INTO endereco (id_cidade, logradouro, numero, bairro, cep, completo, ponto_referencia)
VALUES
(107, 'Alameda das Verbenas', 455, 'Parque Verde', '66633170', '', ''),
(141, 'SQN 202 Bloco A ', 505, 'Asa Norte', '70832010', '', ''),
(4, 'Avenida Paulista', 1055, 'Bela Vista', '01310930', '', ''),
(31, 'Rua Treze de Maio', 1225, 'Centro', '82999921', '', ''),
(1, 'Rua Claudio Passos', 725, 'Vila Rubim', '29025320', '', ''),
(4, 'Rua Sinimbu', 455, 'Liberdade', '01513000', '', ''),
(10, 'Avenida Afonso Pena', 387, 'Centro', '66633170', '', '');

INSERT INTO mae (id_endereco, nome, data_nascimento)
VALUES
(1, 'Anna Medeiros de Mendoça', '1985-12-21'),
(1, 'Maria Aparecida Araujo de Sousa', '1989-02-01'),
(2, 'Ana Pereira Siva', '1990-11-13'),
(2, 'Anna Medeiros de Mendoça', '1985-12-21'),
(1, 'Livia Alencar', '1991-05-14'),
(3, 'Beatriz Feio Pereira', '1985-12-21'),
(4, 'Marta Figueiredo de Azevedo', '1992-12-27'),
(4, 'Amalia Velasco de Azeredo', '1992-12-27'),
(1, 'Zilda Maria Furtado', '1993-10-02'),
(5, 'Larissa Penante da Silva', '1989-07-11'),
(6, 'Ana Clara Marinho Costa', '1997-06-07'),
(7, 'Neida Alvim Amorim', '1995-03-19'),
(7, 'Regina Botelho Tapajós', '1997-09-21'),
(6, 'Marta Rego Barroso', '1996-10-10'),
(6, 'Amelia Teresa Valdez Barros', '1993-01-10'),
(1, 'Cleidiane Texeira Amador', '1995-04-15'),
(1, 'Yasmin Santos Braz', '1993-10-11'),
(2, 'Renata Nascimento Faro', '1995-05-14'),
(3, 'Karol Leao Amador', '1985-12-21');

INSERT INTO telefone_mae (id_mae, numero, tipo)
VALUES -- tipo: 1 = CELULAR; 2 = RESIDENCIA; 3 = TRABALHO
(1, '91 98788-4512', 1),
(2, '91 98787-1412', 1),
(3, '61 3316-1512', 3),
(4, '61 99721-4115', 1),
(5, '91 3210-4519', 2),
(6, '11 98182-2516', 1),
(7, '45 98516-1512', 1),
(8, '45 98488-4512', 1),
(9, '91 98688-4512', 1),
(10, '91 98788-4502', 1),
(11, '35 98187-4417', 1),
(12, '91 98788-4512', 2),
(13, '11 98781-4512', 1),
(15, '31 98788-2512', 1),
(16, '31 98788-5512', 1),
(17, '11 98788-4512', 1),
(18, '11 98788-4521', 1),
(19, '91 99388-1512', 1);

INSERT INTO especialidade (nome)
VALUES
('Pediatra'),('Otorrinolaringologista'),('Ortopedista'),
('Cardiologista'),('Nefrologista'),('Gastrologista'),('Alergista');

INSERT INTO medico (crm, id_especialidade, nome, celular)
VALUES
(1121, 1, 'Antonio Veríssimo', '11 98981 1615'),
(1123, 1, 'Antonia Barbosa', '11 98981 1615'),
(2241, 2, 'Ana Vera Moura', '11 98785 2149'),
(3214, 3, 'Marta Alves', '11 98981 1538'),
(4487, 4, 'Roberto Silveira', '11 98981 1647'),
(4588, 5, 'Mario Oliveira', '11 98981 1127'),
(5611, 6, 'Teresa Borba', '11 98981 7891'),
(7898, 7, 'Maria Celia Santod', '11 98981 9901');

INSERT INTO bebe (crm_medico, id_mae, nome, data_nascimento, peso, altura)
VALUES
(1121, 1, 'Enzo Gabriel Pereira', '2024-04-16', 4.55, 45),
(7898, 1, 'Gariela Pereira', '2023-01-10', 14.55, 78),
(1121, 2, 'Enzo Barros', '2024-04-16', 3.65, 44),
(1123, 3, 'Isabeli Barroso', '2024-05-16', 5.15, 46),
(2241, 4, 'Gabriel Araujo de Azeredo', '2024-01-01', 4.05, 40),
(3214, 4, 'Gabriel Araujo de Azeredo', '2024-01-01', 4.05, 40),
(7898, 4, 'Rafael Araujo de Azeredo', '2023-01-11', 54.05, 80),
(4487, 5, 'Anna Azevedo', '2024-02-01', 4.15, 41),
(4588, 6, 'Gabriele Santos', '2024-03-11', 4.05, 40),
(5611, 4, 'Sophia Texeira', '2024-05-01', 4.35, 41),
(5611, 7, 'Marta Texeira', '2024-05-01', 4.35, 41),
(4588, 7, 'Raquel pereira', '2023-05-02', 14.35, 61),
(1123, 8, 'Silvia Pedrosa', '2024-05-11', 4.05, 40),
(5611, 9, 'Sophia Texeira', '2024-05-01', 4.35, 41),
(1123, 10, 'Ana Amador', '2024-04-01', 4.21, 40),
(1121, 11, 'Larissa Gomes', '2024-05-14', 4.35, 42),
(1123, 12, 'Olivia Braz', '2024-05-27', 4.35, 41),
(5611, 13, 'Sophia Siva', '2024-05-01', 4.35, 41),
(4588, 14, 'Sofia Pereira', '2024-05-01', 4.35, 41),
(1121, 15, 'Bianca Lima', '2024-05-01', 4.35, 41),
(4588, 16, 'Clarice Barros', '2024-05-01', 4.35, 41),
(5611, 17, 'Ana Clara Fernandes', '2024-05-01', 4.35, 41),
(4588, 18, 'Lilica Mato Grosso', '2024-05-01', 4.35, 41),
(1123, 19, 'Ester Balestreri', '2024-05-01', 4.35, 41);