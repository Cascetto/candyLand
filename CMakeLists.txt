cmake_minimum_required(VERSION 3.12.2)
project(isAngryRevised)

set(CMAKE_CXX_STANDARD 14)


include_directories(sfml/include)

set(SOURCE_FILES
        GameLogic/GameEngine.cpp
        GameLogic/AssetManager.cpp
        GameLogic/State/StateHandler.cpp
        GameLogic/State/GameState.cpp
        GameLogic/State/MenuState.cpp
        GameLogic/State/RecordState.cpp
        GameLogic/State/PlayState.cpp
        GameLogic/State/PauseState.cpp
        GameLogic/State/RecordInsState.cpp
        GameLogic/Timer.cpp
        GameLogic/GameFactory.cpp

        GameObjects/Star.cpp
        GameObjects/Bullet.cpp
        GameObjects/Platform.cpp

        GUI/Menu.cpp

        GameCharacter/GameCharacter.cpp
        GameCharacter/Hero.cpp
        GameCharacter/Enemy/Watcher.cpp
        GameCharacter/Enemy/Brawler.cpp
        GameCharacter/Enemy/Archer.cpp
        GameCharacter/Enemy/Boss.cpp
        )

add_subdirectory(unit_testing)

link_directories(./sfml/lib)
link_libraries(libsfml-audio.2.5.1.dylib
        libsfml-audio.2.5.dylib
        libsfml-audio.dylib
        libsfml-graphics.2.5.1.dylib
        libsfml-graphics.2.5.dylib
        libsfml-graphics.dylib
        libsfml-network.2.5.1.dylib
        libsfml-network.2.5.dylib
        libsfml-network.dylib
        libsfml-system.2.5.1.dylib
        libsfml-system.2.5.dylib
        libsfml-system.dylib
        libsfml-window.2.5.1.dylib
        libsfml-window.2.5.dylib
        libsfml-window.dylib)

add_executable(isAngryRevised main.cpp ${SOURCE_FILES})