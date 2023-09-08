package br.test.tdd.domain;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.data.mongodb.core.mapping.Document;
import java.time.LocalDate;

@NoArgsConstructor
@AllArgsConstructor
@Data
@Document(collection = "usuarios")
public class Usuario {
    private String id;
    private String nome;
    private String password;
    private LocalDate dataNascimento;
}
