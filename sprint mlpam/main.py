# PREPARANDO O AMBIENTE
from collections import Counter
import pandas as pd

pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)
pd.set_option('display.width', None)

# CARREGANDO OS DADOS
caminho_arquivo = 'dados.xlsx'
df_original = pd.read_excel(caminho_arquivo)
df = df_original.copy()

print("Total original:", len(df_original))

# TRATAMENTO 
df['vezes_semana'] = pd.to_numeric(df['vezes_semana'], errors='coerce')
df['energia_kwh'] = pd.to_numeric(df['energia_kwh'], errors='coerce')

# Remover apenas linhas com erro nas colunas usadas
df = df.dropna(subset=['vezes_semana', 'energia_kwh'])

# VISUALIZAÇÃO INICIAL
print("DADOS")
print(df.head())

# VARIÁVEL QUANTITATIVA DISCRETA
print("TABELA DISCRETA")

dados_discretos = df['vezes_semana']

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

# Insights
# Usuários com baixa frequência de recarga são minoria
# Frequências intermediárias baixas também têm menor participação

# VARIÁVEL QUANTITATIVA CONTÍNUA
print("TABELA CONTÍNUA")

dados_continuos = df['energia_kwh']

num_classes = 5
classes = pd.cut(dados_continuos, bins=num_classes, right=False)

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

