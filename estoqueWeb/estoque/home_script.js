//Variavel recebe o botao de estoque
let estoque = document.getElementById('botao_estoque')
//Variavel recebe o botao de perfil
let perfil = document.getElementById('botao_perfil')
//Variavel recebe o botao de sair
let sair = document.getElementById('botao_sair')

//Variavel recebe o nome do usuário armazenado no navegador
let nome = localStorage.getItem("nomeUsuario");
//Escreve no h1 a mensagem com o noe do usuário
document.getElementById("nomeUsuario").textContent = `Olá, ${nome}!`;

//Função para ir para a página de estoque
function entrarEstoque(){
    window.location.href = ""
}
//Função para ir para a página de perfil
function entrarPerfil(){
    window.location.href = "perfil.html"
}
//Função para ir para a página de login
function sairHome(){
    window.location.href = "login.html"
}

estoque.addEventListener('click', entrarEstoque)
perfil.addEventListener('click', entrarPerfil)
sair.addEventListener('click', sairHome)