let botao = document.getElementById('botao-novo-produto')

let lista = document.getElementById('listaProdutos')

function criarProduto(){

    let item = document.createElement('tr')

    let nome = document.createElement('td')
    nome.classList.add('produtos-nome')
    nome.textContent = 'Fone de Ouvido Bluetooth'
    item.appendChild(nome)

    let codigo = document.createElement('td')
    codigo.textContent = '7891234560012'
    item.appendChild(codigo)

    let categoria = document.createElement('td')
    categoria.textContent = 'Eletrônicos'
    item.appendChild(categoria)

    let preco = document.createElement('td')
    preco.classList.add('produtos-destaque')
    preco.textContent = 'R$ 189,90'
    item.appendChild(preco)

    let quantidade = document.createElement('td')
    quantidade.classList.add('produtos-destaque')
    quantidade.textContent = '4 un.'
    item.appendChild(quantidade)

    let estoqueMin = document.createElement('td')
    estoqueMin.textContent = '10 un.'
    item.appendChild(estoqueMin)

    let status = document.createElement('td')
    status.classList.add('selo')
    status.textContent = 'Ativo'
    item.appendChild(status)

    let acoes = document.createElement('td')
    item.appendChild(acoes)

    let editar = document.createElement('a')
    editar.classList.add('acao-editar')
    editar.textContent = 'Editar'
    acoes.appendChild(editar)

    let inativar = document.createElement('a')
    inativar.classList.add('acao-inativar')
    inativar.textContent = 'Inativar'
    acoes.appendChild(inativar)

    lista.appendChild(item)
}

botao.addEventListener('click', criarProduto)