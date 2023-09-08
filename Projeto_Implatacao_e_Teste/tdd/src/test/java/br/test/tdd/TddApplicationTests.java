package br.test.tdd;

import br.test.tdd.domain.Usuario;
import br.test.tdd.repository.UsuarioRepository;
import br.test.tdd.service.UsuarioService;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.springframework.boot.test.context.SpringBootTest;
import java.time.LocalDate;


@SpringBootTest
class TddApplicationTests {

	@Mock
	private UsuarioRepository usuarioRepository;

	@InjectMocks
	private UsuarioService usuarioService;

	@Test
	void realizarCadastroUsuario() {
		Usuario usuario = new Usuario(null, "Robson", "123456", LocalDate.of(1981,8,25));
		Usuario usuarioSalvo = usuario;
		usuarioSalvo.setId("1");

		Mockito.when(usuarioRepository.save(usuario)).thenReturn(usuarioSalvo);

		var user = usuarioService.register(usuario);

		Mockito.verify(usuarioRepository).save(usuario);

		Assertions.assertEquals(usuarioSalvo, usuario);
	}

}
