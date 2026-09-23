//Recebe o e-mail do usuário em formato de texto
let inputEmail = document.getElementById('input_email')
//Recebe a senha do usuário em formato de texto
let inputSenha = document.getElementById('input_senha')
//Variável do botão de login
let botaoLogin = document.getElementById('botao_login')

//Verifica o formato do e-mail
function verificarEmail(){
    let email = inputEmail.value.trim()

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

//Verifica se o campo de senha está preenchido
function verificarSenha(){
    let senha = inputSenha.value

    if(senha===""){
        alert("Por favor, digite sua senha")
        return false
    }

    return true
}

//Faz o login se os dados estiverem verificados
function realizarLogin(){
    if(!verificarEmail()){
        return 
    }

    if(!verificarSenha()){
        return 
    }

    //Variáveis novas recebem email e senha
    let email = inputEmail.value.trim()
    let senha = inputSenha.value

    //Aqui o login foi validado
    console.log("E-mail: ", email)
    console.log("Senha: ", senha)
    console.log("Login validado!")

    window.location.href = "home.html"

    //Futuramente será implementado um banco de dados para fazer a validação do email e senha
}

botaoLogin.addEventListener('click', realizarLogin)