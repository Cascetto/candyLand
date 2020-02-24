project(test)

add_subdirectory(gtest_src)

set(TEST_SRC_DIRECTOY gtest_src/googletest)


include_directories(${TEST_SRC_DIRECTORY}/include ${TEST_SRC_DIRECTORY})

set(SOURCE_FILES
        ../GameLogic/GameEngine.cpp
        ../GameLogic/AssetManager.cpp
        ../GameLogic/State/StateHandler.cpp
        ../GameLogic/State/GameState.cpp
        ../GameLogic/State/MenuState.cpp
        ../GameLogic/State/RecordState.cpp
        ../GameLogic/State/PlayState.cpp
        ../GameLogic/ScoreSubject.cpp
        ../GameLogic/ScoreObserver.cpp
        ../GameLogic/Timer.cpp
        ../GameLogic/GameFactory.cpp

        ../GameObjects/Star.cpp
        ../GameObjects/Bullet.cpp
        ../GameObjects/Platform.cpp

        ../GUI/Menu.cpp

        ../GameCharacter/GameCharacter.cpp
        ../GameCharacter/Hero.cpp
        ../GameCharacter/Enemy/Watcher.cpp
        ../GameCharacter/Enemy/Brawler.cpp
        ../GameCharacter/Enemy/Archer.cpp
        ../GameCharacter/Enemy/Boss.cpp
        ../GameObjects/Candy.cpp
        )
include_directories(sfml/include)

link_directories(../sfml/lib)
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

set(TEST_FILES
        factoryTest.cpp enemyTest.cpp heroTest.cpp)

add_executable(test ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(test gtest gtest_main)