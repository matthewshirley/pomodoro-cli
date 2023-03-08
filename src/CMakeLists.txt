add_executable(${POMODORO_PROJECT_NAME}
        ${POMODORO_SRC_DIR}/main.cpp
        ${POMODORO_SRC_DIR}/pomodoro_config.cpp
        ${POMODORO_SRC_DIR}/pomodoro_state.cpp
        ${POMODORO_SRC_DIR}/pomodoro.cpp)

target_compile_features(${POMODORO_PROJECT_NAME} PUBLIC
        cxx_std_20)

target_include_directories(${POMODORO_PROJECT_NAME} PUBLIC 
    ${POMODORO_SRC_DIR}
    ${POMODORO_INC_DIR})
