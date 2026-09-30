//Recebe o nome do usuário
let inputNome = document.getElementById('input_nome')
//Recebe o e-mail do usuário
let inputEmail = document.getElementById('input_email')
//Recebe o telefone do usuário
let inputTelefone = document.getElementById('input_telefone')
//Recebe a senha do usuário
let inputSenha = document.getElementById('input_senha')
//Variável do botão de cadastro
let botaoCadastro = document.getElementById('botao_cadastro')

//Verifica se o campo do nome está preenchido
function verificarNome(){
    let nome = inputNome.value

    if(nome===""){
        alert("Por favor, digite seu nome")
        return false
    }

    return true
}

//Verifica o formato do e-mail
function verificarEmail(){
    let email = inputEmail.value

    //Verifica se o campo do e-mail está preenchido
    if(email===""){
        alert("Por favor, digite seu e-mail")
        return false
    //Verifica se o texto possui o "@"
    }else if(!email.includes("@")){
        alert("Por favor, digite um e-mail válido")
        return false
    }

    return true
}

//Verifica se o campo telefone esta preenchido
function verificarTelefone(){
    let telefone = inputTelefone.value

    if(telefone===""){
        alert("Por favor, digite seu telefone")
        return false
    }

    return true
}

//Verifica se o campo de senha está preenchido
function verificarSenha(){
    let senha = inputSenha.value

    if(senha===""){
        alert("Por favor, digite sua senha")
        return false
    }

    return true
}

//Faz o cadastro se os dados estiverem verificados
function realizarCadastro(){

    if(!verificarNome()){
        return 
    }

    if(!verificarEmail()){
        return 
    }

    if(!verificarTelefone()){
        return 
    }

    if(!verificarSenha()){
        return 
    }

    //Variáveis novas recebem email e senha
    let nome = inputNome.value
    let email = inputEmail.value
    let telefone = inputTelefone.value
    let senha = inputSenha.value

    //Aqui o cadastro foi validado exibe no console os dados (o que seria enviado para o banco de dados)
    console.log("Nome: ", nome)
    console.log("E-mail: ", email)
    console.log("Telefone: ", telefone)
    console.log("Senha: ", senha)
    console.log("Cadastro validado!")

    alert("Cadastro realizado com sucesso!")

    //Armazena no navegador os dados para exibir na página home e de perfil
    localStorage.setItem("nomeUsuario", nome);
    localStorage.setItem("emailUsuario", email);
    localStorage.setItem("telefoneUsuario", telefone);

    //Altera automaticamente para a página de login
    window.location.href = "login.html"

    //Futuramente será implementado um banco de dados para armazear os dados do usuário
}

botaoCadastro.addEventListener('click', realizarCadastro)