main: main.cpp  include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Instance/Path.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp
	g++ main.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Instance/Path.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o main.exe
	clear
	./main.exe

debug: main.cpp  include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Instance/Path.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp
	g++ main.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Instance/Path.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o main.exe
	./main.exe

mac: main.cpp  include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Instance/Path.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp
	g++ main.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Instance/Path.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o main.app
	./main.app