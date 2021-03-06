build/maze.o: maze.cpp maze.h position.h tile.h tilefactory.h
build/tile.o: tile.cpp tile.h
build/floor.o: floor.cpp floor.h tile.h
build/wall.o: wall.cpp wall.h tile.h
build/goal.o: goal.cpp goal.h tile.h
build/mysterytile.o: mysterytile.cpp mysterytile.h tile.h
build/tilefactory.o: tilefactory.cpp wall.h tile.h floor.h goal.h mysterytile.h \
 tilefactory.h
build/game.o: game.cpp game.h entity.h position.h maze.h ui.h gamerules.h \
 entitycontroller.h
build/entity.o: entity.cpp entity.h position.h entitycontroller.h
build/entitycontroller.o: entitycontroller.cpp entitycontroller.h position.h
build/uicontrol.o: uicontrol.cpp uicontrol.h entitycontroller.h position.h \
 game.h ui.h
build/chasehero.o: chasehero.cpp chasehero.h entitycontroller.h position.h \
 game.h entity.h gamerules.h
build/astarchasehero.o: astarchasehero.cpp astarchasehero.h entitycontroller.h \
 position.h
build/inanimate.o: inanimate.cpp inanimate.h entitycontroller.h position.h
build/mysterycontroller.o: mysterycontroller.cpp mysterycontroller.h \
 entitycontroller.h position.h
build/ecfactory.o: ecfactory.cpp uicontrol.h entitycontroller.h position.h \
 chasehero.h astarchasehero.h inanimate.h mysterycontroller.h ecfactory.h
build/ui.o: ui.cpp ui.h position.h
build/gamerules.o: gamerules.cpp gamerules.h game.h basicgamerules.h
build/basicgamerules.o: basicgamerules.cpp basicgamerules.h gamerules.h game.h \
 maze.h tile.h position.h entity.h textui.h ui.h
build/textui.o: textui.cpp textui.h ui.h position.h game.h maze.h tile.h \
 floor.h wall.h goal.h entity.h
build/tctestpp.o: tctestpp.cpp tctestpp.h
build/scriptedcontrol.o: scriptedcontrol.cpp scriptedcontrol.h \
 entitycontroller.h position.h
build/positiontest.o: positiontest.cpp tctestpp.h position.h
build/tiletest.o: tiletest.cpp tctestpp.h tile.h tilefactory.h entity.h \
 position.h
build/mazetest.o: mazetest.cpp tctestpp.h position.h tile.h tilefactory.h \
 textui.h ui.h maze.h
build/gametest.o: gametest.cpp tctestpp.h position.h tile.h maze.h textui.h \
 ui.h entity.h scriptedcontrol.h entitycontroller.h chasehero.h \
 basicgamerules.h gamerules.h game.h ecfactory.h
