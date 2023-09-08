package br.test.tdd.service;

import br.test.tdd.domain.Usuario;
import br.test.tdd.repository.UsuarioRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UsuarioService {
    @Autowired
    private UsuarioRepository usuarioRepository;
    public Usuario register(Usuario u) {
        return usuarioRepository.save(u);
    }
}
