def codificar_mensagem(mensagem):
    """
    Função para codificar mensagem.
    :param mensagem:
    :return: mensagem codificada
    """

    alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    mensagem_codificada = ""
    mapa_codificacao = {}  # Dicionário para registrar as substituições

    for caractere in mensagem:
        if caractere.isalpha():  # Verifica se é uma letra
            indice_aleatorio = (ord(caractere) * 7 + 13) % len(alfabeto)
            nova_letra = alfabeto[indice_aleatorio]

            # Adiciona ao mapa de codificação
            mapa_codificacao[caractere] = nova_letra
            mensagem_codificada += nova_letra
        else:
            mensagem_codificada += caractere  # Mantém os caracteres não alfabéticos

    return mensagem_codificada, mapa_codificacao


def decodificar_mensagem(mensagem_codificada, mapa_codificacao):
    """
    Função que recebe uma mensagem condificada e retorna a mensagem decodificada.

    :param mensagem_codificada:
    :param mapa_codificacao:
    :return:
    """
    
    mensagem_original = ""

    # inverte  dicionárop para decoficar a mensagem
    mapa_decodificacao = {value: key for key, value in mapa_codificacao.items()}

    for caractere in mensagem_codificada:
        if caractere in mapa_decodificacao:  # Substitui pela letra original
            mensagem_original += mapa_decodificacao[caractere]
        else:
            mensagem_original += caractere  # Mantém os caracteres não alfabéticos

    return mensagem_original
