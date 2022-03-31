#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Chel.h"
#include "Vertex.h"
#include "SocialGraph.h"

int Chel::setID = 0;

int main()
{
    Chel* A = new Chel("A");
    Chel* B = new Chel("B");
    Chel* C = new Chel("C");
    Chel* D = new Chel("D");
    Chel* E = new Chel("E");
    Chel* F = new Chel("F");
    Chel* G = new Chel("G");
    Chel* H = new Chel("H");
    Chel* I = new Chel("I");
    Chel* J = new Chel("J");
    Chel* K = new Chel("K");
    Chel* L = new Chel("L");
    Chel* M = new Chel("M");
    Chel* O = new Chel("O");
    Chel* P = new Chel("P");
    Chel* Q = new Chel("Q");
    Chel* R = new Chel("R");

    Vertex* VA = new Vertex(A);
    Vertex* VB = new Vertex(B);
    Vertex* VC = new Vertex(C);
    Vertex* VD = new Vertex(D);
    Vertex* VE = new Vertex(E);
    Vertex* VF = new Vertex(F);
    Vertex* VG = new Vertex(G);
    Vertex* VH = new Vertex(H);
    Vertex* VI = new Vertex(I);
    Vertex* VJ = new Vertex(J);
    Vertex* VK = new Vertex(K);
    Vertex* VL = new Vertex(L);
    Vertex* VM = new Vertex(M);
    Vertex* VO = new Vertex(O);
    Vertex* VP = new Vertex(P);
    Vertex* VQ = new Vertex(Q);
    Vertex* VR = new Vertex(R);

    SocialGraph SG;
    SG.addVertex(VA); SG.addVertex(VB); SG.addVertex(VC); SG.addVertex(VD); SG.addVertex(VE); SG.addVertex(VF); SG.addVertex(VG); SG.addVertex(VH);
    SG.addVertex(VI); SG.addVertex(VJ); SG.addVertex(VK); SG.addVertex(VL); SG.addVertex(VM); SG.addVertex(VO); SG.addVertex(VP); SG.addVertex(VQ);
    SG.addVertex(VR);

    SG.addEdge(VA, VB); SG.addEdge(VA, VC); SG.addEdge(VA, VD); SG.addEdge(VA, VE); SG.addEdge(VA, VF); SG.addEdge(VA, VG); SG.addEdge(VA, VL);
    SG.addEdge(VB, VG);
    SG.addEdge(VD, VL);
    SG.addEdge(VE, VL); SG.addEdge(VE, VK); SG.addEdge(VE, VF);
    SG.addEdge(VF, VG); SG.addEdge(VF, VJ); SG.addEdge(VF, VI); SG.addEdge(VF, VH);
    SG.addEdge(VH, VI); SG.addEdge(VH, VM);
    SG.addEdge(VM, VG); SG.addEdge(VM, VO);
    SG.addEdge(VO, VP);
    SG.addEdge(VP, VQ); SG.addEdge(VP, VR);
    SG.addEdge(VQ, VR);

    int how_deep = 3;
    SG.threeHandshakesForEverybody(how_deep);

    /*
    std::cout << "\n\n\nDEPTH\n\n\n";

    SG.depth(VA);

    std::cout << "\n\n\nSHORTEST\n\n\n";

    std::cout << SG.shortestPath(VA, VM) << "\n";
    */

    delete A; delete B; delete C; delete D; delete E; delete F; delete G; delete H; delete I; delete J; delete K; delete L; delete M; delete O; delete P;
    delete Q; delete R;

    return 0;
}
