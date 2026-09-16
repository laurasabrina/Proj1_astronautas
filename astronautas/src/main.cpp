#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Astronauta{
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;

public:

    Astronauta(string numCpf, string nomeAstronauta, int id){
        cpf = numCpf;
        nome = nomeAstronauta;
        idade = id;
        vivo = true;
        disponivel = true;
    }

    string getCpf(){
        return cpf;
    }

    string getNome(){
        return nome;
    }

    int getIdade(){
        return idade;
    }

    bool estaVivo(){
        return vivo;
    }

    bool estaDisponivel(){
        return disponivel;
    }

    void embarcar(){
        disponivel = false;
    }

    void desembarcar(){
        if(vivo){
            disponivel = true;
        }
    }

    void morrer(){
        vivo = false;
        disponivel = false;
    }

};

class Voo{
private:
    int codigo;
    string estado;
    vector<string> cpfs;

public:

    Voo(int cod){
        codigo = cod;
        estado = "planejado";
    }

    int getCodigo(){
        return codigo;
    }

    string getEstado(){
        return estado;
    }

    int getQuantidadeAstronautas(){
        return cpfs.size();
    }

    string getCpf(int posicao){
        return cpfs[posicao];
    }

    bool temAstronauta(string numCpf){
        for(int i = 0; i < cpfs.size(); i++){
            if(cpfs[i] == numCpf){
                return true;
            }
        }
        return false;
    }

    void adicionarAstronauta(string numCpf){
        cpfs.push_back(numCpf);
    }

    bool removerAstronauta(string numCpf){
        for(int i = 0; i < cpfs.size(); i++){
            if(cpfs[i] == numCpf){
                cpfs.erase(cpfs.begin() + i);
                return true;     // melhoria sugerida pela IA
            }
        }
        return false;
    }

    void lancar(){
        estado = "em curso";
    }

    void explodir(){
        estado = "finalizado com explosao";
    }

    void finalizar(){
        estado = "finalizado com sucesso";
    }

};

class Agencia{
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;
    int buscarAstronauta(string numCpf){
        for(int i = 0; i < astronautas.size(); i++){
            if(astronautas[i].getCpf() == numCpf){
                return i;
            }
        }
        return -1;
    }

    int buscarVoo(int cod){
        for(int i = 0; i < voos.size(); i++){
            if(voos[i].getCodigo() == cod){
                return i;
            }
        }
        return -1;
    }

public:
    void cadastrarAstronauta(string numCpf, string nomeAstronauta, int id){
        if(buscarAstronauta(numCpf) != -1){
            cout << "ERRO: astronauta com CPF " << numCpf << " ja cadastrado" << endl;
            return; 
        }

        Astronauta astronauta(numCpf, nomeAstronauta, id);

        astronautas.push_back(astronauta);

        cout << "OK: astronauta " << numCpf << " cadastrado" << endl;

    }

    void cadastrarVoo(int cod){
        if(buscarVoo(cod) != -1){
            cout << "ERRO: voo " << cod << " ja cadastrado" << endl;
            return;
        }
        Voo voo(cod);

        voos.push_back(voo);

        cout << "OK: voo " << cod << " cadastrado" << endl;

    }

    void adicionarAstronauta(string numCpf, int cod){
        int posicaoAstronauta = buscarAstronauta(numCpf);
        int posicaoVoo = buscarVoo(cod);

        if(posicaoAstronauta == -1){
            cout << "ERRO: astronauta " << numCpf << " nao cadastrado" << endl;
            return;
        }

        if(posicaoVoo == -1){
            cout << "ERRO: voo " << cod << " nao cadastrado" << endl;
            return;
        }

        if(voos[posicaoVoo].getEstado() != "planejado"){
            cout << "ERRO: voo " << cod << " nao esta planejado" << endl;
            return;
        }

        if(!astronautas[posicaoAstronauta].estaVivo()){
            cout << "ERRO: astronauta " << numCpf << " esta morto" << endl;
            return;
        }

        if(voos[posicaoVoo].temAstronauta(numCpf)){
            cout << "ERRO: astronauta " << numCpf << " ja esta no voo " << cod << endl;
            return;
        }

        voos[posicaoVoo].adicionarAstronauta(numCpf);

        cout << "OK: astronauta " << numCpf << " adicionado ao voo " << cod << endl;

    }
    
    void removerAstronauta(string numCpf, int cod){
        int posicaoAstronauta = buscarAstronauta(numCpf);
        int posicaoVoo = buscarVoo(cod);

        if(posicaoAstronauta == -1){
            cout << "ERRO: astronauta " << numCpf << " nao cadastrado" << endl;
            return;
        }

        if(posicaoVoo == -1){
            cout << "ERRO: voo " << cod << " nao cadastrado" << endl;
            return;
        }

        if(voos[posicaoVoo].getEstado() != "planejado"){
            cout << "ERRO: voo " << cod << " nao esta planejado" << endl;
            return;
        }

        if(!voos[posicaoVoo].temAstronauta(numCpf)){
            cout << "ERRO: astronauta " << numCpf << " nao esta no voo " << cod << endl;
            return;
        }

        voos[posicaoVoo].removerAstronauta(numCpf);

        cout << "OK: astronauta " << numCpf << " removido do voo " << cod << endl;

    }
    
    void lancarVoo(int cod){
        int posicaoVoo = buscarVoo(cod);

        if(posicaoVoo == -1){
            cout << "ERRO: voo " << cod << " nao cadastrado" << endl;
            return;
        }

        if(voos[posicaoVoo].getEstado() != "planejado"){
            cout << "ERRO: voo " << cod << " nao esta planejado" << endl;
            return;
        }

        if(voos[posicaoVoo].getQuantidadeAstronautas() == 0){
            cout << "ERRO: voo " << cod << " nao possui astronautas" << endl;
            return;
        }

        for(int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++){
            
            string numCpf = voos[posicaoVoo].getCpf(i);

            int posicaoAstronauta = buscarAstronauta(numCpf);

            if(!astronautas[posicaoAstronauta].estaVivo()){
                cout << "ERRO: astronauta " << numCpf << " esta morto" << endl;
                return;
            }

            if(!astronautas[posicaoAstronauta].estaDisponivel()){
                cout << "ERRO: astronauta " << numCpf << " esta indisponivel" << endl;
                return;
            }            
        }

        for(int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++){
            string numCpf = voos[posicaoVoo].getCpf(i);
            
            int posicaoAstronauta = buscarAstronauta(numCpf);

            astronautas[posicaoAstronauta].embarcar();
        }

        voos[posicaoVoo].lancar();

        cout << "OK: voo " << cod << " lancado" << endl;
        
    }
    
    void explodirVoo(int cod){

        int posicaoVoo = buscarVoo(cod);
        
        if(posicaoVoo == -1){
                cout << "ERRO: voo " << cod << " nao cadastrado" << endl;
                return;
        }

        if(voos[posicaoVoo].getEstado() != "em curso"){
            cout << "ERRO: voo " << cod << " nao esta em curso" << endl;
            return;
        }

        for(int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++){
            string numCpf = voos[posicaoVoo]. getCpf(i);

            int posicaoAstronauta = buscarAstronauta(numCpf);

            astronautas[posicaoAstronauta].morrer();

        }
        voos[posicaoVoo].explodir();

        cout << "OK: voo " << cod << " explodiu" << endl;
    
    }
    
    void finalizarVoo(int cod){

        int posicaoVoo = buscarVoo(cod);
        
        if(posicaoVoo == -1){
                cout << "ERRO: voo " << cod << " nao cadastrado" << endl;
                return;
        }

        if(voos[posicaoVoo].getEstado() != "em curso"){
            cout << "ERRO: voo " << cod << " nao esta em curso" << endl;
            return;
        }

        for(int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++){
            string numCpf = voos[posicaoVoo]. getCpf(i);

            int posicaoAstronauta = buscarAstronauta(numCpf);

            astronautas[posicaoAstronauta].desembarcar();

        }
        voos[posicaoVoo].finalizar();

        cout << "OK: voo " << cod << " finalizado com sucesso" << endl;

    }
    
    void listarVoos(){
        cout << "LISTA DE VOOS" << endl;

        string estados[4] = {"planejado", "em curso", "finalizado com sucesso", "finalizado com explosao"};

        for(int k = 0; k < 4; k++){
            cout << "== " << estados[k] << " ==" << endl;
            
            bool encontrou = false;

            for(int i = 0; i < voos.size(); i++){
                if(voos[i].getEstado() == estados[k]){
                    encontrou = true;

                    cout << "Voo " << voos[i].getCodigo() << ": ";

                    if(voos[i].getQuantidadeAstronautas() == 0){
                        cout << "sem astronautas";
                    } else{
                        for(int j = 0; j < voos[i].getQuantidadeAstronautas(); j++){
                            string numCpf = voos[i].getCpf(j);

                            int posicaoAstronauta = buscarAstronauta(numCpf);
                            cout << numCpf << " " << astronautas[posicaoAstronauta].getNome();

                            if(j + 1 < voos[i].getQuantidadeAstronautas()){
                                cout << ", ";
                            }
                        }
                    }
                    cout << endl;
                }
            }
            if(!encontrou){
                cout << "(nenhum)" << endl;
            }
        }
    }
    
    void listarMortos(){

        cout << "ASTRONAUTAS MORTOS" << endl;

        bool encontrou = false;

        for(int i = 0; i < astronautas.size(); i++){
            if(!astronautas[i].estaVivo()){
                encontrou = true;

                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " - voos:";
                
                bool participou = false;

                for(int j = 0; j < voos.size(); j++){
                    if(voos[j].getEstado() != "planejado"){
                        if(voos[j].temAstronauta(astronautas[i].getCpf())){
                            cout << " " << voos[j].getCodigo();

                            participou = true;
                        }
                    }
                }
                if(!participou){
                    cout << " nenhum";
                }

                cout << endl;
            } 
        }
        if(!encontrou){
            cout << "(nenhum)" << endl;
        }
    }
};


int main() {
    Agencia agencia;
    string comando;

    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);   // o nome vem por ultimo e pode ter espacos
            agencia.cadastrarAstronauta(cpf, nome, idade);
        } else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            agencia.listarMortos();
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}
