valor_inicial = float(input())
taxa_juros_anual = float(input())
periodo_tempos = int(input())

taxa_juros_anual = taxa_juros_anual / 100

def calculo_juros():
  juros_tempo = (1 + taxa_juros_anual) ** periodo_tempos
  calculo = valor_inicial * (juros_tempo)
  return calculo
print(f"Valor final do investimento: R$ {calculo_juros():.2f}\n")