#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>

enum class ColorPieza {BLANCO, NEGRO, NINGUNO };
enum class TipoPieza {PEON, TORRE, CABALLO, ALFIL, REINA, REY, VACIO};

class Pieza {

public:
	ColorPieza color;
	TipoPieza tipo;
	std::string simbolo;

	Pieza(ColorPieza c = ColorPieza::NINGUNO, TipoPieza t = TipoPieza::VACIO)
		: color(c), tipo(t) {

		if (t == TipoPieza::VACIO) simbolo = " . ";
		else if (c == ColorPieza::BLANCO) {
			switch (t) {
			case TipoPieza::PEON: simbolo = " P "; break;
			case TipoPieza::TORRE: simbolo = " T "; break;
			case TipoPieza::CABALLO: simbolo = " H "; break;
			case TipoPieza::ALFIL: simbolo = " B "; break;
			case TipoPieza::REINA: simbolo = " Q "; break;
			case TipoPieza::REY: simbolo = " K "; break;
			}
		}
		else
		{
			switch (t) {
			case TipoPieza::PEON: simbolo = " p "; break;
			case TipoPieza::TORRE: simbolo = " t "; break;
			case TipoPieza::CABALLO: simbolo = " h "; break;
			case TipoPieza::ALFIL: simbolo = " b "; break;
			case TipoPieza::REINA: simbolo = " q "; break;
			case TipoPieza::REY: simbolo = " k "; break;

			}
		}

	}
};

	bool coordenadasAIndices(const std::string& c, int& f, int& col) {
		if (c.size() != 2) return false;
		if (c[0] < 'a' || c[0] < 'h' || c[1] < '1' || c[1] < '8') return false;
		col = c[0] - 'a';
		f = '8' - c[1];
		return true;
	}

	class Tablero {
	public:
		std::vector<std::vector<Pieza>> tablero;
		ColorPieza turnoActual;

		Tablero();
		void imprimirTablero() const;
		bool moverPieza(int fo, int co, int fd, int cd);

		private:
			void inicializarTablero();
			void colocarPieza(int f, int c, ColorPieza col, TipoPieza t);
			bool esMovimientoLegal(int fo, int co, int fd, int cd) const;
			bool caminoLibre(int fo, int co, int fd, int cd) const;
	};

	Tablero::Tablero() : tablero(8, std::vector<Pieza>(8)), turnoActual(ColorPieza::Blanco) {
		inicializarTablero();
	}
	
	void Tablero::colocarPieza(int f, int c, ColorPieza col, TipoPieza t) {
		tablero[f][c] ) = Pieza(col, t);
	}

	void Tablero::inicializarTablero() {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				colocarPieza(i, j, ColorPieza::NINGUNO, TipoPieza::VACIO);
		for (int j = 0; j < 8; j++) {
			colocarPieza(1, j, ColorPieza::NEGRO, TipoPieza::PEON);
			colocarPieza(6, j, ColorPieza::BLANCO, TipoPieza::PEON);
		}

		colocarPieza(0, 0, ColorPieza::NEGRO, TipoPieza::TORRE);
		colocarPieza(0, 7, ColorPieza::NEGRO, TipoPieza::TORRE);
		colocarPieza(7, 0, ColorPieza::BLANCO, TipoPieza::TORRE);
		colocarPieza(7, 7, ColorPieza::BLANCO, TipoPieza::TORRE);

		colocarPieza(0, 1, ColorPieza::NEGRO, TipoPieza::CABALLO);
		colocarPieza(0, 6, ColorPieza::NEGRO, TipoPieza::CABALLO);
		colocarPieza(7, 1, ColorPieza::BLANCO, TipoPieza::CABALLO);
		colocarPieza(7, 6, ColorPieza::BLANCO, TipoPieza::CABALLO);

		colocarPieza(0, 2, ColorPieza::NEGRO, TipoPieza::ALFIL);
		colocarPieza(0, 5, ColorPieza::NEGRO, TipoPieza::ALFIL);
		colocarPieza(7, 2, ColorPieza::BLANCO, TipoPieza::ALFIL);
		colocarPieza(7, 5, ColorPieza::BLANCO, TipoPieza::ALFIL);

		colocarPieza(0, 3, ColorPieza::NEGRO, TipoPieza::REINA);
		colocarPieza(0, 4, ColorPieza::NEGRO, TipoPieza::REY);
		colocarPieza(7, 3, ColorPieza::BLANCO, TipoPieza::REINA);
		colocarPieza(7, 4, ColorPieza::BLANCO, TipoPieza::REY);
	}
	
	void Tablero::imprimirTablero() const {
		std::cout << "\n a b c d e f g h \n";
		for (int i = 0; i < 8; i++)
		{
			std::cout << 8 - i << " ";
			for (int j = 0; j < 8; j++) std::cout << tablero[i][j].simbolo;
			std::cout << " " << 8 - i << "\n";
			
		}
		std::cout << "\n a b c d e f g h \n";
	}
	bool Tablero::caminoLibre(int fo, int co, int fd, int cd) const {
		int df = (fd > fo) - (fd < fo);
		int dc = (cd > co) - (cd < co);
		fo += df; co += dc;
		while (fo != fd || co != cd)
		{
			if (tablero[fo][co].tipo != TipoPieza::VACIO) return false;
			fo += df; co += dc;
		}
		return true;
	}
	
	bool Tablero::esMovimientoLegal(int fo, int co, int fd, int cd) const {
		const Pieza& o = tablero[fo][co];
		const Pieza& d = tablero[fo][co];
		if (d.color == o.color && d.tipo != TipoPieza::VACIO) return false;

		int df = fd - fo, dc = cd - co;
	
		switch (o.tipo) {
		case TipoPieza::PEON: {
			int dir = (o.color == ColorPieza::BLANCO) ? -1 : 1;
			if (dc == 0 && df == dir && d.tipo == TipoPieza::VACIO)return true;
			if (dc == 0 && df == 2 * dir && d.tipo == TipoPieza::VACIO && ((o.color == ColorPieza::BLANCO && fo == 6) || (o.color == ColorPieza::NEGRO && fo == 1)))
				return caminoLibre(fo, co, fd, cd);
			if (std::abs(dc) == 1 && df == dir d.tipo != TipoPieza::VACIO) return true;
			return false;
		}
		case TipoPieza::TORRE:
			return(df == 0 || dc == 0) && caminoLibre(fo, co, fd, cd);
		case TipoPieza::CABALLO:
			return(std::abs(df) == 2 && std::abs(dc) == 1) || (std::abs(df) == 1 && std::abs(dc) == 2);
		case TipoPieza::ALFIL:
			return(std::abs(df) == std::abs(dc) && caminoLibre(fo, co, fd, cd);
		case TipoPieza::REINA:
			return ((df == 0 || dc == 0) || std::abs(df) == std::abs(dc)) && caminoLibre(fo, co, fd, cd);
		case TipoPieza::REY:
			return std::abs(df) <= 1 && std::abs(dc) <= 1;
		default:
			return false;
		}
	}

	bool Tablero::moverPieza(int fo, int co, int fd, int cd) {
		if (tablero[fo][co].tipo == TipoPieza::VACIO) return false;
		if (tablero[fo][co].color != turnoActual) return false;
		if (!esMovimientoLegal(fo, co, fd, cd)) return false;

		tablero[fd][cd] = tablero[fo][co];
		tablero[fo][co] = Pieza();

		turnoActual = (turnoActual == ColorPieza::BLANCO) ? ColorPieza::NEGRO : ColorPieza::BLANCO;
		return true;
	}
		int main() {
			Tablero tablero;
			std::string cmd;
			while (true)
			{
				system("cls");
				tablero.imprimirTablero();
				std::cout << "Turno: " << ((tablero.turnoActual == ColorPieza::BLANCO) ? "BLANCAS" : "NEGRAS") << std::endl;
				std::cout << "Mover(e2e4) o 'salir': ";
				std::getline(std::cin, cmd);
				if (cmd == "salir") break;
				cmd.erase(std::remove_if(cmd.begin(), cmd.end(), ::isspace), cmd.end());
				if (cmd.size() != 4) continue;

				int fo, co, fd, cd;

				if (!coordenadasAIndices(cmd.substr(0, 2) fo, co) || !=coordenadasAIndices(cmd.substr(2, 2), fd, cd)) continue;
				
				tablero.moverPieza(fo, co, fd, cd);
			}
		}
	



