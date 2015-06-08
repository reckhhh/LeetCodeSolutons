/*
 Find the total area covered by two rectilinear rectangles in a 2D plane.
 
 Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 
 Assume that the total area is never beyond the maximum possible value of int.
 
 Tags: Math
*/
int max(int a, int b)   {return a > b ? a : b;}
int min(int a, int b)   {return a < b ? a : b;}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int first   = (C - A) * (D - B);
    int second  = (G - E) * (H - F);
    
    int overlap = max( min(C, G) - max(A, E), 0) *
    max( min(D, H) - max(B, F), 0);
    
    return first + second - overlap;
}