#include "GhostSpawner.h"
#include "Ghost.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height){
    this->em = em;
    this->sprite = sprite;
    if (numGhosts < 8) {
        spawnGhost("red");
        numGhosts++;
    }
    if (numGhosts < 8) {
        spawnGhost("pink");
        numGhosts++;
    }
    if (numGhosts < 8) {
        spawnGhost("cyan");
        numGhosts++;
    }
    if (numGhosts < 8) {
        spawnGhost("orange");
        numGhosts++;
    }

}

void GhostSpawner::tick(){
    std::vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if(em->ghosts.size()<4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }else{
            spawnCounter--;
        }
    }
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}

void GhostSpawner::keyPressed(int key){
     if(key == 'g' &&  numGhosts < 8){  
        std::vector<std::string> ghost_colors = {"red", "pink", "cyan", "orange"}; 
        int random_index = std::rand() % ghost_colors.size();  
        spawnGhost(ghost_colors[random_index]);  
        numGhosts++;  
    }
}