#include "tctestpp.h"
#include "game.h"
#include "maze.h"
#include "textui.h"
#include <sstream>
#include <string>


Maze *readFromString(const std::string &s) {
	std::stringstream ss(s);
	return Maze::read(ss);
}


const char *m1 =
	"10 6\n"
  "##########\n"
  "#........#\n"
  "#.###....#\n"
  "#.#......#\n"
  "#.....<..#\n"
  "##########\n";

	const char *m1_maze =
  "##########\n"
  "#........#\n"
  "#.###....#\n"
  "#.#......#\n"
  "#.....<..#\n"
  "##########\n";

struct TestObjs {
	Game *t_game;
	Maze *maze1;
	TextUI *t_ui;
	std::string OGMaze;
};

TestObjs *setup() {
	TestObjs *objs = new TestObjs;
	objs->t_game = new Game();
	objs->t_ui = new TextUI();
	objs->maze1 = readFromString(m1);
	objs->t_game->setMaze(objs->maze1);
	std::stringstream ss(m1_maze);
	objs->OGMaze = ss.str();
	return objs;
}

void cleanup(TestObjs *objs) {
	delete objs->t_game;
	delete objs->maze1;
	delete objs->t_ui;
	delete objs;
}

void testRender(TestObjs *objs);

int main(int argc, char* argv[]) {
	TEST_INIT();

	if (argc > 1) {
		tctest_testname_to_execute = argv[1];
	}

	TEST(testRender);

	TEST_FINI();
}

void testRender(TestObjs *objs) {
	//redirect cout to a string stream
	std::stringstream renderOutput;
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(renderOutput.rdbuf());
	//call render
	objs->t_ui->render(objs->t_game);
	//direct cout back to cout
	std::cout.rdbuf(coutbuf);

	//Sanity Checks
	//std::cout << renderOutput.str() << std::endl;
	//std::cout << objs->OGMaze << std::endl;

	ASSERT(renderOutput.str() == objs->OGMaze);

}