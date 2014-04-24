include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/StyleCheckDependencies.cmake)
if(PYTHONINTERP_FOUND)
  #Style Configuration
  # Complains about any c-style cast -> too annoying.
  set(STYLE_FILTER -readability/casting)

  # Insists on including evrything in the .cpp file even if it is included in the header.
  set(STYLE_FILTER ${STYLE_FILTER},-build/include_what_you_use)

  # Ohh this is questionable
  set(STYLE_FILTER ${STYLE_FILTER},-build/header_guard)

  # Too many false positives and not very helpful error messages.
  set(STYLE_FILTER ${STYLE_FILTER},-build/include_order)

  # No thanks.
  set(STYLE_FILTER ${STYLE_FILTER},-readability/streams)

  # Ugh!
  set(STYLE_FILTER ${STYLE_FILTER},-whitespace/tab)

  # Yes it is!
  set(STYLE_FILTER ${STYLE_FILTER},-whitespace/blank_line)

  # Suggessts excessive indentation.
  set(STYLE_FILTER ${STYLE_FILTER},-whitespace/labels)

  # Don't tell me how to name my variables.
  set(STYLE_FILTER ${STYLE_FILTER},-runtime/arrays)

  # Why?
  set(STYLE_FILTER ${STYLE_FILTER},-whitespace/todo)
  set(STYLE_FILTER ${STYLE_FILTER},-readability/todo)

  # Annoyting to use with boost::program_options
  set(STYLE_FILTER ${STYLE_FILTER},-whitespace/semicolon)

  # Add a target that runs cpplint.py
  #
  # Parameters:
  # - TARGET_NAME the name of the target to add
  # - SOURCES_LIST a complete list of source and include files to check
  function(add_style_check_target TARGET_NAME SOURCES_LIST)
    if(NOT PYTHON_EXECUTABLE)
      return()
    endif(NOT PYTHON_EXECUTABLE)
    list(SORT SOURCES_LIST)
    list(REMOVE_DUPLICATES SOURCES_LIST)

    set(FINAL_LIST)

    # add directory prefix
    foreach(l ${SOURCES_LIST})
      file(GLOB_RECURSE LIST_FILES ${CMAKE_SOURCE_DIR} ${l}/*.cpp;${l}/*.h;${l}/*.hxx;${l}/*.hpp;${l}/*.cxx;${l}/*.cc;${l}/*.cpp.in;${l}/*.h.in;${l}/*.hxx.in;${l}/*.hpp.in;${l}/*.cxx.in;${l}/*.cc.in)
      list(APPEND FINAL_LIST ${LIST_FILES} )
    endforeach()

    add_custom_target(${TARGET_NAME}
     COMMAND "${CMAKE_COMMAND}" -E chdir
              "${CMAKE_SOURCE_DIR}"
              "${PYTHON_EXECUTABLE}"
              "${CMAKE_SOURCE_DIR}/CMake/cpplint.py"
              "--filter=${STYLE_FILTER}"
              ${FINAL_LIST}
      DEPENDS ${SOURCES_LIST}
      COMMENT "Checking code style."
      VERBATIM
    )

  endfunction(add_style_check_target)

else(PYTHONINTERP_FOUND)
    message(WARNING "Python is not found, cpplint can't run to check the code.")
endif(PYTHONINTERP_FOUND)
