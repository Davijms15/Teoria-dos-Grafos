#Opção para compilar e executar em apenas um comando

compile_Dijkstra_Exec:
		g++ Dijkstra.cpp -o a && ./a <in.txt

compile_Bellman_Ford_Exec:
		g++ Bellman_Ford.cpp -o a && ./a <in.txt

compile_Floyd_Warshall_Exec:
		g++ Floyd_Warshall.cpp -o a && ./a <in.txt		

compile_Kruskal_Exec:
		g++ Kruskal.cpp -o a && ./a <in.txt

compile_Prim_Exec:
		g++ Prim.cpp -o a && ./a <in.txt

compile_Ford_Fulkerson_Exec:
		g++ Ford_Fulkerson.cpp -o a && ./a <in.txt

#Opção para apenas compilar

compile_Dijkstra:
		g++ Dijkstra.cpp -o a

compile_Bellman_Ford:
		g++ Bellman_Ford.cpp -o a

compile_Floyd_Warshall:
		g++ Floyd_Warshall.cpp -o a		

compile_Kruskal:
		g++ Kruskal.cpp -o a

compile_Prim:
		g++ Prim.cpp -o a

compile_Ford_Fulkerson:
		g++ Ford_Fulkerson.cpp -o a