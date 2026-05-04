# preparando o ambiente
from collections import Counter
import pandas as pd

pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)
pd.set_option('display.width', None)

# criando os dataframes
caminho_arquivo = 'dados.xlsx'
df_original = pd.read_excel(caminho_arquivo)
# dataframe copia do original
df = df_original.copy()

# total de dados
print("Total original:", len(df_original))

# selecionando as colunas, criando as tabelas e transformando em numeros
df['vezes_semana'] = pd.to_numeric(df['vezes_semana'], errors='coerce')
df['energia_kwh'] = pd.to_numeric(df['energia_kwh'], errors='coerce')

# remover apenas linhas com erro nas colunas usadas
df = df.dropna(subset=['vezes_semana', 'energia_kwh'])

# mostrando os primeiros dados da tabela
print("dados")
print(df.head())

print()

# variavel quantitativa discreta
print("tabela discreta")

# selecionando a coluna vezes_semana do dataframe df
dados_discretos = df['vezes_semana']

# criando as variaveis das frequencias
fi = pd.Series(Counter(dados_discretos)).sort_index()
fia = fi.cumsum()
fr = 100 * fi / fi.sum()
fra = fr.cumsum()

tabela_discreta = pd.DataFrame({
    'Frequencia_Absoluta': fi,
    'Frequencia_Acumulada': fia,
    'Frequencia_Relativa': fr,
    'Frequencia_Relativa_Acumulada': fra
})

total = pd.Series({
    'Frequencia_Absoluta': fi.sum(),
    'Frequencia_Acumulada': pd.NA,
    'Frequencia_Relativa': fr.sum(),
    'Frequencia_Relativa_Acumulada': pd.NA
}, name='Total')

tabela_discreta = pd.concat([tabela_discreta, total.to_frame().T])

print(tabela_discreta)

print()

# Insights
# Usuários com baixa frequência de recarga são minoria
# Frequências intermediárias baixas também têm menor participação

# variavel quantitativa continua
print("TABELA CONTÍNUA")

# selecionando a coluna energia_kwh do dataframe df
dados_continuos = df['energia_kwh']

# numero de classes
num_classes = 5
classes = pd.cut(dados_continuos, bins=num_classes, right=False)

# criando as variaveis das frequencias
fi = classes.value_counts().sort_index()
fia = fi.cumsum()
fr = (100 * fi / fi.sum()).round(2)
fra = fr.cumsum()

tabela_continua = pd.DataFrame({
    'Frequencia_Absoluta': fi,
    'Frequencia_Acumulada': fia,
    'Frequencia_Relativa': fr,
    'Frequencia_Relativa_Acumulada': fra
})

total = pd.Series({
    'Frequencia_Absoluta': fi.sum(),
    'Frequencia_Acumulada': pd.NA,
    'Frequencia_Relativa': fr.sum().round(2),
    'Frequencia_Relativa_Acumulada': pd.NA
}, name='Total')

tabela_continua = pd.concat([tabela_continua, total.to_frame().T])

print(tabela_continua)

# Insights
# O consumo está concentrado em faixas intermediárias de energia
# Recargas de consumo muito elevado são menos frequentes

