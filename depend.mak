build/maze.o: maze.cpp
build/tile.o: tile.cpp tile.h
build/floor.o: floor.cpp
build/wall.o: wall.cpp wall.h tile.h
build/goal.o: goal.cpp
build/mysterytile.o: mysterytile.cpp mysterytile.h tile.h
build/tilefactory.o: tilefactory.cpp wall.h tile.h floor.h goal.h mysterytile.h \
 tilefactory.h
build/game.o: game.cpp
build/entity.o: entity.cpp
build/entitycontroller.o: entitycontroller.cpp entitycontroller.h position.h
build/uicontrol.o: uicontrol.cpp
build/chasehero.o: chasehero.cpp
build/astarchasehero.o: astarchasehero.cpp
build/inanimate.o: inanimate.cpp
build/mysterycontroller.o: mysterycontroller.cpp mysterycontroller.h \
 entitycontroller.h position.h
build/ecfactory.o: ecfactory.cpp uicontrol.h entitycontroller.h position.h \
 chasehero.h astarchasehero.h inanimate.h mysterycontroller.h ecfactory.h
build/ui.o: ui.cpp ui.h position.h
build/gamerules.o: gamerules.cpp gamerules.h game.h
build/basicgamerules.o: basicgamerules.cpp
build/tctestpp.o: tctestpp.cpp tctestpp.h
build/scriptedcontrol.o: scriptedcontrol.cpp scriptedcontrol.h \
 entitycontroller.h position.h
build/positiontest.o: positiontest.cpp tctestpp.h position.h
build/tiletest.o: tiletest.cpp tctestpp.h tile.h tilefactory.h entity.h \
 position.h
build/mazetest.o: mazetest.cpp tctestpp.h position.h tile.h maze.h
build/gametest.o: gametest.cpp tctestpp.h position.h tile.h maze.h entity.h \
 scriptedcontrol.h entitycontroller.h basicgamerules.h gamerules.h game.h
