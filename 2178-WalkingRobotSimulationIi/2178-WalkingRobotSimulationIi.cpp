// Last updated: 20/07/2026, 11:26:27
class Robot {
public:
    int width, height;
    int x = 0, y = 0;
    int dir = 0;

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
    }
    
    void step(int num) {
        int perimeter = 2 * (width + height) - 4;
        
        num %= perimeter;

        if (num == 0) num = perimeter;

        while (num--) {
            if (dir == 0) {
                if (x + 1 < width) x++;
                else { dir = 1; y++; }
            }
            else if (dir == 1) {
                if (y + 1 < height) y++;
                else { dir = 2; x--; }
            }
            else if (dir == 2) {
                if (x - 1 >= 0) x--;
                else { dir = 3; y--; }
            }
            else {
                if (y - 1 >= 0) y--;
                else { dir = 0; x++; }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};