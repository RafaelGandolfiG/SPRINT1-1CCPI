# ============================================================
# PREPARANDO O AMBIENTE
# ============================================================
from collections import Counter
import pandas as pd

pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)
pd.set_option('display.width', None)

# ============================================================
# CARREGANDO OS DADOS
# ============================================================
caminho_arquivo = r"C:\Users\Rafael\Documents\SPRINT1-1CCPI\sprint mlpam\dados.xlsx"

df_original = pd.read_excel(caminho_arquivo)
df = df_original.copy()

print("Total original:", len(df_original))

# ============================================================
# TRATAMENTO (como ensinado na aula)
# ============================================================
df['vezes_semana'] = pd.to_numeric(df['vezes_semana'], errors='coerce')
df['energia_kwh'] = pd.to_numeric(df['energia_kwh'], errors='coerce')

# Remover apenas linhas com erro nas colunas usadas
df = df.dropna(subset=['vezes_semana', 'energia_kwh'])

print("Total após limpeza:", len(df))

# ============================================================
# VISUALIZAÇÃO INICIAL
# ============================================================
print("\n=== DADOS ===\n")
print(df.head())

# ============================================================
# VARIÁVEL QUANTITATIVA DISCRETA (vezes_semana)
# ============================================================
print("\n=== TABELA DISCRETA ===\n")

dados_discretos = df['vezes_semana']

fi = pd.Series(Counter(dados_discretos)).sort_index()
fia = fi.cumsum()
fr = 100 * fi / fi.sum()
fra = fr.cumsum()

tabela_discreta = pd.DataFrame({
    'Frequencia_Absoluta': fi,
    'Frequencia_Acumulada': fia,
    'Frequencia_Relativa (%)': fr.round(2),
    'Frequencia_Relativa_Acumulada (%)': fra.round(2)
})

# Linha total (igual aula)
total = pd.Series({
    'Frequencia_Absoluta': fi.sum(),
    'Frequencia_Acumulada': pd.NA,
    'Frequencia_Relativa (%)': fr.sum().round(2),
    'Frequencia_Relativa_Acumulada (%)': pd.NA
}, name='Total')

tabela_discreta = pd.concat([tabela_discreta, total.to_frame().T])

print(tabela_discreta)

# ============================================================
# VARIÁVEL QUANTITATIVA CONTÍNUA (energia_kwh)
# ============================================================
print("\n=== TABELA CONTÍNUA ===\n")

dados_continuos = df['energia_kwh']

# Seguindo a lógica da aula (intervalos)
num_classes = 5
classes = pd.cut(dados_continuos, bins=num_classes)

fi = classes.value_counts().sort_index()
fia = fi.cumsum()
fr = (100 * fi / fi.sum()).round(2)
fra = fr.cumsum()

tabela_continua = pd.DataFrame({
    'Frequencia_Absoluta': fi,
    'Frequencia_Acumulada': fia,
    'Frequencia_Relativa (%)': fr,
    'Frequencia_Relativa_Acumulada (%)': fra
})

total = pd.Series({
    'Frequencia_Absoluta': fi.sum(),
    'Frequencia_Acumulada': pd.NA,
    'Frequencia_Relativa (%)': fr.sum(),
    'Frequencia_Relativa_Acumulada (%)': pd.NA
}, name='Total')

tabela_continua = pd.concat([tabela_continua, total.to_frame().T])

print(tabela_continua)

# ============================================================
# ESTATÍSTICAS DESCRITIVAS
# ============================================================
print("\n=== ESTATÍSTICAS ===\n")

print("Vezes por semana:")
print(df['vezes_semana'].describe())

print("\nEnergia (kWh):")
print(df['energia_kwh'].describe())

# ============================================================
# INSIGHTS (igual a lógica da aula)
# ============================================================
print("\n=== INSIGHTS ===\n")

print("Variável Discreta:")
print("- Identifica a frequência de uso semanal dos usuários.")
print("- Permite entender comportamento de recarga.")

print("\nVariável Contínua:")
print("- Mostra a distribuição do consumo de energia.")
print("- Ajuda a identificar padrões de consumo.")

# ============================================================
# FINAL
# ============================================================
print("\nAnálise finalizada!")