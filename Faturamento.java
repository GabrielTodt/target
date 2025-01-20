import org.json.JSONArray;
import org.json.JSONObject;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Faturamento {

    public static void main(String[] args) {
        String caminhoArquivo = "./dados.json";

        try {
            
            String conteudoJson = new String(Files.readAllBytes(Paths.get(caminhoArquivo)));

            // Parse do JSON
            JSONArray faturamentoArray = new JSONArray(conteudoJson);

            double menorValor = Double.MAX_VALUE;
            double maiorValor = Double.MIN_VALUE;
            double soma = 0.0;
            int diasComFaturamento = 0;

            // Calcula menor, maior valor e soma dos valores válidos
            for (int i = 0; i < faturamentoArray.length(); i++) {
                JSONObject dia = faturamentoArray.getJSONObject(i);
                double valor = dia.getDouble("valor");

                if (valor > 0) {
                    if (valor < menorValor) {
                        menorValor = valor;
                    }
                    if (valor > maiorValor) {
                        maiorValor = valor;
                    }
                    soma += valor;
                    diasComFaturamento++;
                }
            }

            // Calcular a média
            double media = soma / diasComFaturamento;

            // Contar os dias com faturamento superior à média
            int diasAcimaDaMedia = 0;
            for (int i = 0; i < faturamentoArray.length(); i++) {
                JSONObject dia = faturamentoArray.getJSONObject(i);
                double valor = dia.getDouble("valor");

                if (valor > 0 && valor > media) {
                    diasAcimaDaMedia++;
                }
            }

            System.out.println("Menor valor de faturamento: " + menorValor);
            System.out.println("Maior valor de faturamento: " + maiorValor);
            System.out.println("Número de dias com faturamento acima da média: " + diasAcimaDaMedia);

        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Erro ao processar os dados: " + e.getMessage());
        }
    }
}
