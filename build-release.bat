windres resource.rc -O coff -o resource.res
g++ -Wall -o Doggenstein main.cpp resource.res -lglu32 -lglut32 -lopengl32
exit