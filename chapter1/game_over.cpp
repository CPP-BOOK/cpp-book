/* Game Over
 * A first C++ program
 */

#include <iostream> // permite usar std::cout, es decir, contiene la definición del objeto.

/* Permite usar los objetos de la librería std sin "std::". Es decir, fija el ámbito de este
 * fichero dentro de std.
 * Esto se hace así porque yo podría crearme un objeto "cout" y el compilador no tendría forma
 * de saber a cuál de los dos me refiero. */
// using namespace std;

/* Permite definir el uso de std::cout sin "std::" SÓLO para este objeto, y no para toda la
 * librería std. */
using std::cout;
using std::endl;

int main() {
	cout << "GAME OVER 3" << endl;
	return 0;
}
