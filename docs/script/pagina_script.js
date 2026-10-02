//Cria o grafico de Vendas por Canal

const data = {
    labels: ['Janeiro', 'Fevereiro', 'Março'],

    datasets: [
        {
            label: 'E-Commerce',

            data: [10, 20, 30],

            borderColor: '#b48215d0',
            backgroundColor: '#e9a81aad',

            borderWidth: 2,
            borderRadius: Number.MAX_VALUE,
            borderSkipped: false
        },

        {
            label: 'Loja Física',

            data: [15, 25, 20, 35],

            borderColor: '#534733cb',
            backgroundColor: '#6e5e43cc',

            borderWidth: 2,
            borderRadius: 5,
            borderSkipped: false
        }
    ]
};

const config = {
    type: 'bar',

    data: data,

    options: {
        responsive: true,
        maintainAspectRatio: false,

        plugins: {
            legend: {
                position: 'top'
            },

            title: {
                display: true,
                text: 'Comparativo de Vendas'
            }
        }
    }
};

const graficoVendas = document.getElementById('grafico-vendas');

new Chart(graficoVendas, config);

//Adiciona itens na lista de Alertas de Estoque 
let botao = document.getElementById('botao-ver-relatorios')

let listaAlerta = document.getElementById('alertas-lista')

function adicionarItemAlerta(){

    let item = document.createElement('li')
    item.classList.add('alertas-estoque-item')

    let icone = document.createElement('span')
    icone.classList.add('alertas-estoque-icone')
    icone.textContent = '▣'
    item.appendChild(icone)

    let info = document.createElement('div')
    info.classList.add('alertas-estoque-info')
    item.appendChild(info)

    let nome = document.createElement('h3')
    nome.textContent = 'Teclado Mecânico RGB'
    info.appendChild(nome)

    let descricao = document.createElement('p')
    descricao.textContent = 'Periféricos · Mínimo: 8 un.'
    info.appendChild(descricao)

    let estoque = document.createElement('div')
    estoque.classList.add('alertas-estoque-qtd')
    item.appendChild(estoque)

    let qtd = document.createElement('p')
    qtd.classList.add('qtd')
    qtd.textContent = '7 un.'
    estoque.appendChild(qtd)

    let status = document.createElement('p')
    status.textContent = 'Em estoque'
    estoque.appendChild(status)

    listaAlerta.appendChild(item)
}

//Adiciona itens na lista de Sugestão de Compra

let listaSugestao = document.getElementById('listaSugestao')

//

function adicionarItemSugestao(){

    let linhaItem = document.createElement('tr')

    let nomeItemSugestao = document.createElement('td')
    nomeItemSugestao.classList.add('sugestoes-produto')
    nomeItemSugestao.textContent = 'Carregador Portátil 10.000mAh'
    linhaItem.appendChild(nomeItemSugestao)

    let categoriaItemSugestao = document.createElement('td')
    categoriaItemSugestao.textContent = 'Acessórios'
    linhaItem.appendChild(categoriaItemSugestao)

    let qtdAtualItemSugestao = document.createElement('td')
    qtdAtualItemSugestao.classList.add('qtd')
    qtdAtualItemSugestao.textContent = '0 un.'
    linhaItem.appendChild(qtdAtualItemSugestao)

    let qtdMinItemSugestao = document.createElement('td')
    qtdMinItemSugestao.textContent = '6 un.'
    linhaItem.appendChild(qtdMinItemSugestao)

    let qtdCompraItemSugestao = document.createElement('td')
    qtdCompraItemSugestao.classList.add('sugestoes-compra')
    qtdCompraItemSugestao.textContent = '12 un.'
    linhaItem.appendChild(qtdCompraItemSugestao)

    let statusItemSugestao = document.createElement('td')
    linhaItem.appendChild(statusItemSugestao)

    let seloItemSugestao = document.createElement('span')
    seloItemSugestao.classList.add('selo', 'selo-zerado')
    seloItemSugestao.textContent = 'Zerado'
    statusItemSugestao.appendChild(seloItemSugestao)

    listaSugestao.appendChild(linhaItem)
}

function adicionarItens() {

    adicionarItemAlerta()
    adicionarItemSugestao()

}

botao.addEventListener('click', adicionarItens)