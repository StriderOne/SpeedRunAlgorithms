#include <iostream>

struct vert {
    char sym;
    int n;
};

void del_duone(struct vert* v1, struct vert* v2){
    v1->n--;
    v2->n--;
    std::cout << v1->sym  << v2->sym << "-\n";
};

void add_duone(struct vert* v1, struct vert* v2){
    v1->n++;
    v2->n++;
    std::cout << v1->sym  << v2->sym << "+\n";
};

int main() {

    struct vert verts[8];
    for (size_t i = 0; i < 8; i++)
    {
        verts[i] = {char('A'+i)};
        std::cin >> verts[i].n;
    }
    int sum1 = verts['A'-'A'].n + verts['C'-'A'].n + verts['F'-'A'].n + verts['H'-'A'].n;
    int sum2 = verts['B'-'A'].n + verts['D'-'A'].n + verts['G'-'A'].n + verts['E'-'A'].n;
    if (sum1 != sum2){
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }

    while (sum1 > 0)
    {
        if (verts['A' - 'A'].n != 0){
            if (verts['B'-'A'].n != 0) {
                del_duone(&verts['A'-'A'],&verts['B'-'A']);
            }else if (verts['D'-'A'].n != 0) {
                del_duone(&verts['A'-'A'],&verts['D'-'A']);
            }else if (verts['E'-'A'].n != 0) {
                del_duone(&verts['A'-'A'],&verts['E'-'A']);
            } else if (verts['G'-'A'].n != 0) {
                add_duone(&verts['B'-'A'],&verts['C'-'A']);
                del_duone(&verts['A'-'A'],&verts['B'-'A']);
                del_duone(&verts['C'-'A'],&verts['G'-'A']);
            }
        } else if (verts['C' - 'A'].n != 0){
            if (verts['B'-'A'].n != 0) {
                del_duone(&verts['C'-'A'],&verts['B'-'A']);
            }else if (verts['D'-'A'].n != 0) {
                del_duone(&verts['C'-'A'],&verts['D'-'A']);
            }else if (verts['G'-'A'].n != 0) {
                del_duone(&verts['C'-'A'],&verts['G'-'A']);
            } else if (verts['E'-'A'].n != 0) {
                add_duone(&verts['B'-'A'],&verts['A'-'A']);
                del_duone(&verts['C'-'A'],&verts['B'-'A']);
                del_duone(&verts['A'-'A'],&verts['E'-'A']);
            }
        } else if (verts['H' - 'A'].n != 0){
            if (verts['G'-'A'].n != 0) {
                del_duone(&verts['H'-'A'],&verts['G'-'A']);
            }else if (verts['E'-'A'].n != 0) {
                del_duone(&verts['H'-'A'],&verts['E'-'A']);
            }else if (verts['D'-'A'].n != 0) {
                del_duone(&verts['H'-'A'],&verts['D'-'A']);
            } else if (verts['B'-'A'].n != 0) {
                add_duone(&verts['A'-'A'],&verts['D'-'A']);
                del_duone(&verts['D'-'A'],&verts['H'-'A']);
                del_duone(&verts['A'-'A'],&verts['B'-'A']);
            }
        } else if (verts['F' - 'A'].n != 0){
            if (verts['G'-'A'].n != 0) {
                del_duone(&verts['F'-'A'],&verts['G'-'A']);
            }else if (verts['E'-'A'].n != 0) {
                del_duone(&verts['F'-'A'],&verts['E'-'A']);
            }else if (verts['B'-'A'].n != 0) {
                del_duone(&verts['F'-'A'],&verts['B'-'A']);
            } else if (verts['D'-'A'].n != 0) {
                add_duone(&verts['A'-'A'],&verts['B'-'A']);
                del_duone(&verts['B'-'A'],&verts['F'-'A']);
                del_duone(&verts['A'-'A'],&verts['D'-'A']);
            }
        }
        sum1 -= 1;
    }
    

    return 0;
}