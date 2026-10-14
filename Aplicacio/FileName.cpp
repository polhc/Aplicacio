#include <iostream>
#include <string>
using namespace std;

class Sessio_Usuari {
private:
	std::string nomUsuari;
	int tempsLlimitSegons;
	bool activa;

	void tancarSessio() {
		activa = false;
	}

public:
	Sessio_Usuari() {
		nomUsuari = "convidat";
		tempsLlimitSegons = 300;
		activa = true;
	}
	explicit Sessio_Usuari(std::string nom) {
		nomUsuari = nom;
		tempsLlimitSegons = 600;
		activa = true;

	}
	Sessio_Usuari(std::string nom, int temps) {
		nomUsuari = nom;
		activa = true;
		if (temps <= 0) {
			tempsLlimitSegons = 60;
		}
		else {
			tempsLlimitSegons = temps;
		}

	}

	~Sessio_Usuari() {
		if (activa) {
			tancarSessio();
			cout << "[AUDITORIA] La sessió de '" << nomUsuari << "' s'ha tancat automàticament en sortir d'àmbit.\n";
		}
	}

	std::string getNomUsuari() const{
		return nomUsuari;
	}
	bool isActiva() const{
		return activa;
	}
	void ampliarTemps(int segons) {
		if (segons > 0) {
			tempsLlimitSegons = tempsLlimitSegons + segons;
		}	
	}
};

int main() {
	string nombre;
	int num;
	cout << "introdueix el nom:" << endl;
	cin >> nombre;
	cout << "introdueix el temps:" << endl;
	cin >> num;
	Sessio_Usuari sessio1(nombre, num);
	cout << "El nom es:" << sessio1.getNomUsuari() << endl;
	if (sessio1.isActiva()) {
		cout << "L'estat esta actiu" << endl;
	}
	else {
		cout << "L'estat No esta actiu" << endl;
	}

	sessio1.ampliarTemps(30);
}