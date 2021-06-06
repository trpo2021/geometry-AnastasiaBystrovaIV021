CXX=g++
CFLAGS=-Wall -Wextra -Werror -I src/ -I thirdparty/
GEOMETRY_SRC = src/geometry/
LIBGEOMETRY_SRC = src/libgeometry/

GEOMETRY_OBJ = obj/src/geometry/
LIBGEOMETRY_OBJ = obj/src/libgeometry/

GEOMETRY_BIN = bin/

SRC = src/

.PHONY: geometry

$(GEOMETRY_BIN)geometry: $(GEOMETRY_OBJ)main.o $(LIBGEOMETRY_OBJ)libgeometry.a
	$(CXX) $(CFLAGS) -o $@ $^
$(GEOMETRY_OBJ)main.o: $(GEOMETRY_SRC)geometrymain.cpp 
	$(CXX) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)libgeometry.a: $(LIBGEOMETRY_OBJ)CheckCircle.o  $(LIBGEOMETRY_OBJ)Radius.o $(LIBGEOMETRY_OBJ)PerimeterAndArea.o
	ar rcs $@ $^
$(LIBGEOMETRY_OBJ)CheckCircle.o: $(LIBGEOMETRY_SRC)CheckCircle.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)isGoodCircle.o: $(LIBGEOMETRY_SRC)Radius.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)PerimeterArea.o: $(LIBGEOMETRY_SRC)PerimeterAndArea.cpp
	$(CXX) -c $(CFLAGS) -o $@ $

.PHONY: format

format:
	git ls-files *.{cpp,h} | xargs clang-format -i
	git add .
	git commit -m "Format code"