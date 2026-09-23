let home = document.getElementById('botao_home')

function voltarHome(){
    window.location.href = "home.html"
}

let nome = localStorage.getItem("nomeUsuario");

document.getElementById("nomeUsuario").textContent =nome;

let email = localStorage.getItem("emailUsuario");

document.getElementById("emailUsuario").textContent = email;

let telefone = localStorage.getItem("telefoneUsuario");

document.getElementById("telefoneUsuario").textContent = telefone;

home.addEventListener('click', voltarHome)