#include <bits/stdc++.h>

using namespace std;
char mp[600][600];
char ch[32][20][20]={
	{
		{"......##......."},
		{".......##......"},
		{"###############"},
		{"..............."},
		{"..###########.."},
		{"..#.........#.."},
		{"..#.........#.."},
		{"..#.........#.."},
		{"..###########.."},
		{".......#......."},
		{"...#...#...#..."},
		{"..##...#...##.."},
		{"..#....#....##."},
		{".#.....#.....#."},
		{"#...####.....##"}
	},
	{
		{".#.......#....."},
		{"..##.#########."},
		{"...#.....#...#."},
		{".........#...#."},
		{"#...###########"},
		{"##.......#...#."},
		{".##......#...#."},
		{"..#..#########."},
		{".........#....."},
		{"...#.#########."},
		{"..#......#....."},
		{"..#......#....."},
		{".##.###########"},
		{".#.......#....."},
		{"##.......#....."},
	},
	{
		{".....#..##..##."},
		{"######..####..#"},
		{"....##..#######"},
		{"####.#........."},
		{"..###########.."},
		{"..#....#....#.."},
		{"..###########.."},
		{"..#....#....#.."},
		{"..###########.."},
		{"....#.....#...."},
		{".#############."},
		{"....#.....#...."},
		{"###############"},
		{"...###...####.."},
		{"###..........##"},
	},
	{
		{".#############."},
		{".....#...#....."},
		{"..#..#...#..#.."},
		{"..##.#...#..#.."},
		{"...#.#...#.#..."},
		{".....#...#....."},
		{"###############"},
		{"..............."},
		{"..###########.."},
		{"..#.........#.."},
		{"..#.........#.."},
		{"..###########.."},
		{"..#.........#.."},
		{"..#.........#.."},
		{"..###########.."},
	},
	{
		{"....#.....#...."},
		{"###############"},
		{"....#.....#...."},
		{".#############."},
		{".#...........#."},
		{".#.#########.#."},
		{"..............."},
		{".#############."},
		{"....###....#..."},
		{".###..##..###.."},
		{"#...##.###....."},
		{"#.##..###.#...."},
		{".#...##.#..#..."},
		{"..####..#...##."},
		{"##....##.....##"},		
	},
	{
		{"##............."},
		{".##..##########"},
		{"..#.........##."},
		{"...#.......##.."},
		{"..........##..."},
		{".........##...."},
		{"###......##...."},
		{"..#......##...."},
		{"..#......##...."},
		{"..#......##...."},
		{"..#......##...."},
		{"..#......##...."},
		{".###...###....."},
		{"##.##........##"},
		{"#....#########."},
	},
	{
		{".......#......."},
		{".......#......."},
		{"###############"},
		{".......#......."},
		{".......#......."},
		{".......#......."},
		{".#############."},
		{"..............."},
		{"..............."},
		{"..###########.."},
		{"..#.........#.."},
		{"..#.........#.."},
		{"..#.........#.."},
		{"..#.........#.."},
		{"..###########.."},
	},
	{
		{"..###########.."},
		{"..#....#....#.."},
		{"..#.#..#..#.#.."},
		{"..#..#.#.#..#.."},
		{"..#.#..#.#..#.."},
		{"..###########.."},
		{".......#......."},
		{".#############."},
		{".......#......."},
		{".......#......."},
		{"###############"},
		{"..............."},
		{"..#..#..##..##."},
		{".#...#...#...#."},
		{"##...#...#....#"},
	},
	{
		{".#......##....."},
		{"..##.....##...."},
		{"...#......#...."},
		{"......########."},
		{"......#......#."},
		{"##....#......#."},
		{"..##..#......#."},
		{"......########."},
		{"......#......#."},
		{"...#.##........"},
		{"..##.##........"},
		{"..#..#........."},
		{".##..#........."},
		{".#..##........."},
		{"##.##.........."},
	},
	{
		{"....#.....#...."},
		{"###############"},
		{"....#.....#...."},
		{"....#.....#...."},
		{"......#........"},
		{"......#........"},
		{".###########..."},
		{"......#....#..."},
		{"..#...#....##.."},
		{"..##.##....#.#."},
		{".##..#.....#.##"},
		{"##..##.....#..#"},
		{"...##.....##..."},
		{"..##...#..##..."},
		{"##......###...."},
	},
	{
		{"##....#......##"},
		{"..##..#..####.."},
		{"...#..#..##...."},
		{"....#######...."},
		{"#.....#..##...."},
		{"##....#..######"},
		{"..#...#..##.##."},
		{"......#####.##."},
		{"...#####.##.##."},
		{"..#.#.#..#..##."},
		{"..#...#..#..##."},
		{".##...#..#..##."},
		{".#....#..#..##."},
		{"##....#.#...##."},
		{"#...###.#...##."},		
	},
	{
		{"..##.....##...."},
		{"..#.......#...."},
		{"..#...#########"},
		{"#####.#.......#"},
		{"##..#.#.......#"},
		{"##..#..#######."},
		{"##..#.........."},
		{"#####.........."},
		{"##..#.#########"},
		{"##..#...##.#..."},
		{"##..#...#..#..."},
		{"#####...#..#..."},
		{"##.....##..#..#"},
		{"##....##...#..#"},
		{".....#.....####"},		
	},
	{
		{".#...#########."},
		{"..#..........#."},
		{"...#.........#."},
		{".......#.....#."},
		{".#.....#.....#."},
		{".#.#########.#."},
		{".#.##..#..##.#."},
		{".#.##..#..##.#."},
		{".#.##..#..##.#."},
		{".#.#########.#."},
		{".#.....#..#..#."},
		{".#.....#..#..#."},
		{".#.....#####.#."},
		{".#.#####...#.#."},
		{".#..........##."},
	},
	{
		{"..##.....#....."},
		{"#######.######."},
		{".#...#.###..#.."},
		{".#...#....##..."},
		{"##########..###"},
		{".........#####."},
		{".######....#..."},
		{".#....#########"},
		{".######........"},
		{".#....#.######."},
		{".######.#....#."},
		{"...#....#..#.#."},
		{"#######.#.#..#."},
		{"...#.....#####."},
		{"...#...##.....#"},
	},
	{
		{"....##........."},
		{"...#######....."},
		{"..##....##....."},
		{".############.."},
		{"#.#....#....#.."},
		{"..###########.."},
		{"..#....#....#.."},
		{"###############"},
		{"..............."},
		{"..###########.."},
		{"..##.......##.."},
		{"..###########.."},
		{"..##.......##.."},
		{"..##.......##.."},
		{"..###########.."},
	},
	{
		{"######..#......"},
		{"....#..######.."},
		{".#.#...#...#..."},
		{"####.##########"},
		{"..##..#...#..##"},
		{"...#..#...#..##"},
		{"###############"},
		{"..#.#...##....#"},
		{"..#.####.##.##."},
		{"..#.#.#..####.."},
		{"..#....##.#.#.."},
		{"..#..##..#.#.#."},
		{"..#....##..#.##"},
		{"..#..##...#...#"},
		{"###.....###...."},
	},
	{
		{"####.####.#####"},
		{"#..#.#..#.#..##"},
		{"#..#.#..#.#..#."},
		{"#..#.#..#.#..#."},
		{"####.####.#.#.."},
		{"..........#.#.."},
		{".#######..#.##."},
		{"..........#..#."},
		{"#########.#...#"},
		{"..#.......#...#"},
		{".#######..#...#"},
		{".......#..#####"},
		{".......#..#...."},
		{"......##..#...."},
		{"...####...#...."},
	},
	{
		{"##....#..######"},
		{".##...#..##..##"},
		{"...#..#..##..##"},
		{"......#..##..##"},
		{"#...#######..##"},
		{"##....#..######"},
		{".##..##..##..##"},
		{".....###.##..##"},
		{".....######..##"},
		{"..#.#.#.#######"},
		{"..#.#.#..##..##"},
		{".#.#..#..##..##"},
		{".#.#..#..##..##"},
		{"##....#..######"},
		{"#.....#..##..##"},
	},
	{
		{"......##......."},
		{"..###########.."},
		{"..#.#..#..#.#.."},
		{"..#..#.#.#..#.."},
		{"..###########.."},
		{"..#..###.#..#.."},
		{"..###..#..#.#.."},
		{"..###########.."},
		{"..............."},
		{"###############"},
		{"...#..........."},
		{"..###########.."},
		{"............#.."},
		{"...........##.."},
		{"........####..."},
	},
	{
		{"..#.......#...."},
		{"..#.......#...."},
		{"..#...########."},
		{"#####.....#...."},
		{"..#.......#...."},
		{"..##......#...."},
		{".###.##########"},
		{".##.#.........."},
		{".##.#.....#...."},
		{"#.#.......#...."},
		{"#.#...#########"},
		{"#.#.......#...."},
		{"..#.......#...."},
		{"..#.......#...."},
		{"..#..##########"},
	},
	{
		{".........##...."},
		{"#####.....#...."},
		{"..#...#########"},
		{"..#............"},
		{"..#....#######."},
		{"..#....#.....#."},
		{"#####..#.....#."},
		{"..#....#.....#."},
		{"..#....#######."},
		{"..#.......#...."},
		{"..#....#..#.##."},
		{"..###.##..#..#."},
		{"###...#...#..##"},
		{".....#.#..#...#"},
		{"........###...."},
	},
	{
		{"##.......##...."},
		{".###....###...."},
		{"...#...##.##..."},
		{".....##.....###"},
		{"#..##.#######.#"},
		{"##............."},
		{"..#..#####.#.#."},
		{".....#..##.#.#."},
		{".....#####.#.#."},
		{"..#..#..##.#.#."},
		{"..#..#..##.#.#."},
		{".##..#####.#.#."},
		{".#...#..##...#."},
		{"##...#..##...#."},
		{"#....#.##..###."},
	},
	{
		{"..#..........#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{"..#....#.....#."},
		{".##....#.....#."},
		{".#.....#.....#."},
		{".#.....#.....#."},
		{"##.....#.....#."},
		{"#............#."},
	},
	{
		{".......#......."},
		{"..###########.."},
		{"..#....#....#.."},
		{"..###########.."},
		{".......#......."},
		{"###############"},
		{"..............."},
		{"..###########.."},
		{"..##.......##.."},
		{"..##...#...##.."},
		{"..##...#...##.."},
		{"..##..##...##.."},
		{".....##.###...."},
		{"...###.....####"},
		{"###..........#."},
	},
	{
		{"..............."},
		{"..###########.."},
		{"..............."},
		{"..............."},
		{"..............."},
		{"..............."},
		{"###############"},
		{".....##........"},
		{".....#........."},
		{"....##....#...."},
		{"....#.....##..."},
		{"...##......##.."},
		{"...#........#.."},
		{"..##...#######."},
		{".#######.....##"},
	},
	{
		{"....#.....#...."},
		{"###############"},
		{"....#.....#.#.."},
		{"..........#..#."},
		{"#..############"},
		{"#..#......#...."},
		{"#..#.######..#."},
		{".###.#.#..##.#."},
		{"...#.#####.###."},
		{"####.#...#.##.."},
		{".#.#.#####.##.."},
		{".#.#.#.#...#..."},
		{".#.#.########.#"},
		{"#.#..#...##.#.#"},
		{"#.#.....##...##"},
	},
	{
		{"#####.....#...."},
		{"#...#.....#...."},
		{"#..#..#########"},
		{"#..#......#...."},
		{"#.#....#..#..#."},
		{"#.##...#..#.##."},
		{"#..#...#..#.#.."},
		{"#...#..####.#.."},
		{"#...#.#########"},
		{"#...#....##...."},
		{"#.##.....###..."},
		{"#.......##.#..."},
		{"#......##...#.."},
		{"#.....##....##."},
		{"#...##........#"},
	},
	{
		{"...#.......#..."},
		{"...#.......#..."},
		{"...#.......#..."},
		{"###############"},
		{"...#.......#..."},
		{"...#.......#..."},
		{"...#.......#..."},
		{"...#.......#..."},
		{"...#########..."},
		{"...#.......#..."},
		{"...#.......#..."},
		{"...#.......#..."},
		{"...#.......#..."},
		{"...#########..."},
		{"...#.......#..."},
	},
	{
		{".......#......."},
		{".#############."},
		{".......#......."},
		{"..###########.."},
		{".......#......."},
		{"###############"},
		{"..............."},
		{"..###########.."},
		{"..##.......##.."},
		{"..###########.."},
		{"..##.......##.."},
		{"..###########.."},
		{"..##.......##.."},
		{"..##.......##.."},
		{"..##.....###..."},
	},
	{
		{"......##......."},
		{".......##......"},
		{".#############."},
		{".#...........#."},
		{".#...........#."},
		{"..............."},
		{"###############"},
		{".......#......."},
		{".......#......."},
		{".......#......."},
		{".......#......."},
		{".......#......."},
		{".......#......."},
		{".......#......."},
		{"....####......."},
	},
	{
		{"...#........###"},
		{"#############.."},
		{".#...##.##....."},
		{"..#..#..##....."},
		{"..#..#..##....."},
		{"##########....."},
		{"...#....#######"},
		{"...#....##..#.."},
		{"##########..#.."},
		{"...#....##..#.."},
		{".#.#.##.#...#.."},
		{".#.#..#.#...#.."},
		{"#..#..#.#...#.."},
		{"...#...##...#.."},
		{"..##...#....#.."},
	}
};
bool check_ch(char c[20][20],int x, int y){
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			if(c[i][j] != mp[x+i][y+j]) return 0;
		}
	}
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			mp[x+i][y+j] = '.';
		}
	}
	return 1;
}
int nx = 0,ny = 0;
int find_ch(){
	for(int j = ny; j+14 < 500;j++){
		for(int i = nx; i+14 < 500; i++){
			for(int k = 0; k < 31; k++){
				if(check_ch(ch[k],i,j)){
					nx = i,ny = j;
					return k;
				} 
			}
		}
	}
	return 12345;
}

char number[12][20][10] = {
	{
		{"..#####.."},
		{".######.."},
		{"##....##."},
		{"##....##."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##....##."},
		{"##....##."},
		{".######.."},
		{"..####..."},
	},
	{
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
	},
	{
		{"..#####.."},
		{".#######."},
		{"##....##."},
		{".......##"},
		{"......##."},
		{"......##."},
		{"......##."},
		{".....##.."},
		{"....###.."},
		{"...###..."},
		{"...##...."},
		{"..###...."},
		{".###....."},
		{".##......"},
		{"###......"},
		{"########."},
		{"########."},
	},
	{
		{"########."},
		{"########."},
		{".....###."},
		{"....###.."},
		{"...###..."},
		{"..###...."},
		{"..#####.."},
		{"..######."},
		{"......##."},
		{"......##."},
		{"......##."},
		{"......##."},
		{"##....##."},
		{"##....##."},
		{"###...##."},
		{".######.."},
		{"..####..."},
	},
	{
		{".....##.."},
		{"....###.."},
		{"....###.."},
		{"...####.."},
		{"...####.."},
		{"...####.."},
		{"..#####.."},
		{"..##.##.."},
		{".###.##.."},
		{".##..##.."},
		{".##..##.."},
		{"##...##.."},
		{"#########"},
		{"#########"},
		{".....##.."},
		{".....##.."},
		{".....##.."},
	},
	{
		{"########."},
		{"########."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"#######.."},
		{"########."},
		{"......###"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{"##.....##"},
		{".##...###"},
		{".#######."},
		{"..#####.."},
	},
	{
		{".....#..."},
		{"....##..."},
		{"...##...."},
		{"..###...."},
		{"..##....."},
		{".##......"},
		{".##......"},
		{".#####..."},
		{"#######.."},
		{"###...##."},
		{"##....##."},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"###...##."},
		{".#######."},
		{"..####..."},
	},
	{
		{"#########"},
		{"#########"},
		{".......#."},
		{"......##."},
		{"......##."},
		{".....##.."},
		{".....##.."},
		{".....#..."},
		{"....##..."},
		{"....##..."},
		{"....##..."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
	},
	{
		{"..#####.."},
		{".##...##."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##....##."},
		{".##..###."},
		{"..#####.."},
		{".#######."},
		{"##....##."},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"###..###."},
		{".######.."},
		{"...###..."},
	},
	{
		{".######.."},
		{".##..###."},
		{"##....##."},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##....##."},
		{".#######."},
		{"..######."},
		{".....###."},
		{".....##.."},
		{"....###.."},
		{"....##..."},
		{"...##...."},
		{"..###...."},
		{".###....."},
		{"........."},
	}
};
char eng[30][20][10] = {
	{
		{"...##...."},
		{"...###..."},
		{"...###..."},
		{"..####..."},
		{"..####..."},
		{"..##.#..."},
		{"..##.##.."},
		{"..##.##.."},
		{".###.##.."},
		{".##..##.."},
		{".##...#.."},
		{".##...##."},
		{".#######."},
		{"########."},
		{"##....##."},
		{"##....##."},
		{"##.....##"},
	},
	{
		{"#######.."},
		{"##....##."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##....##."},
		{"########."},
		{"#######.."},
		{"##...###."},
		{"##....##."},
		{"##.....#."},
		{"##.....#."},
		{"##.....#."},
		{"##....##."},
		{"##....##."},
		{"#######.."},
		{"######..."},
	},
	{
		{"..#####.."},
		{".##..###."},
		{"##.....##"},
		{"##.....##"},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##.....##"},
		{"##.....##"},
		{"###...##."},
		{".######.."},
		{"...###..."},
	},
	{
		{"#######.."},
		{"#....###."},
		{"#......#."},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......##"},
		{"#......#."},
		{"#.....##."},
		{"#######.."},
		{"######..."},
	},
	{
		{"########."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"#######.."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"########."},
		{"########."},
	},
	{
		{".#######."},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".######.."},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
		{".##......"},
	},
	{
		{"..#####.."},
		{".##...##."},
		{"##.....##"},
		{"##.....##"},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##.######"},
		{"##.######"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"###...##."},
		{".######.."},
		{"...###..."},
	},
	{
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"#########"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
	},
	{
		{"xxxxx"}
	},
	{
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{".......##"},
		{"##.....##"},
		{"##.....##"},
		{"###...##."},
		{".######.."},
		{"...###..."},
	},
	{
		{"##....##."},
		{"##...##.."},
		{"##...##.."},
		{"##..##..."},
		{"##.###..."},
		{"##.###..."},
		{"######..."},
		{"######..."},
		{"###..##.."},
		{"###..##.."},
		{"##...##.."},
		{"##....#.."},
		{"##....##."},
		{"##....##."},
		{"##....##."},
		{"##.....##"},
		{"##.....##"},
	},
	{
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"#########"},
		{"#########"},
	},
	{
		{"##....###"},
		{"###...###"},
		{"###..####"},
		{"####.####"},
		{"######.##"},
		{"##.##..##"},
		{"##..#..##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
	},
	{
		{"##.....##"},
		{"##.....##"},
		{"###....##"},
		{"###....##"},
		{"####...##"},
		{"####...##"},
		{"##.##..##"},
		{"##.##..##"},
		{"##.##..##"},
		{"##..##.##"},
		{"##..##.##"},
		{"##...####"},
		{"##...####"},
		{"##....###"},
		{"##....###"},
		{"##....###"},
		{"##.....##"},
	},
	{
		{"xxxxxx"}
	},
	{
		{"#######.."},
		{"##....##."},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##....##."},
		{"########."},
		{"#######.."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
		{"##......."},
	},
	{
		{"..#####.."},
		{".##..###."},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##..##.##"},
		{"##...####"},
		{".##..###."},
		{".#######."},
		{"...#####."},
	},
	{
		{"#######.."},
		{"##....##."},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##....##."},
		{"########."},
		{"#######.."},
		{"##..##..."},
		{"##..##..."},
		{"##...##.."},
		{"##...##.."},
		{"##....##."},
		{"##....##."},
		{"##....##."},
		{"##.....##"},
	},
	{
		{"..#####.."},
		{".###.###."},
		{"##....##."},
		{"##.....##"},
		{"##......."},
		{"##......."},
		{"###......"},
		{".#####..."},
		{"..#####.."},
		{"......##."},
		{".......##"},
		{".......##"},
		{".......##"},
		{"##.....#."},
		{".##...##."},
		{".######.."},
		{"...###..."},
	},
	{
		{"#########"},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
	},
	{
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"##.....##"},
		{"###...##."},
		{".######.."},
		{"...###..."},
	},
	{
		{"##.....##"},
		{"##....##."},
		{".#....##."},
		{".##...##."},
		{".##...##."},
		{".##...##."},
		{".##..##.."},
		{"..#..##.."},
		{"..##.##.."},
		{"..##.##.."},
		{"..##.##.."},
		{"..####..."},
		{"...###..."},
		{"...###..."},
		{"...###..."},
		{"...##...."},
		{"...##...."},
	},
	{
		{"#......##"},
		{"#...#..##"},
		{"#...#..##"},
		{"#...#..##"},
		{"##.##..#."},
		{"##.##..#."},
		{"##.##..#."},
		{".#.#####."},
		{".#.#####."},
		{".#.#####."},
		{".#######."},
		{".###.##.."},
		{".###.##.."},
		{".###.##.."},
		{"..#..##.."},
		{"..#..##.."},
		{"..#..##.."},
	},
	{
		{"##....##."},
		{"###...##."},
		{".##...##."},
		{".##..##.."},
		{"..##.##.."},
		{"..####..."},
		{"...###..."},
		{"...###..."},
		{"...###..."},
		{"...###..."},
		{"..####..."},
		{"..##.##.."},
		{".###.##.."},
		{".##...##."},
		{".##...##."},
		{"##....##."},
		{"##.....##"},
	},
	{
		{"##....##."},
		{".##...##."},
		{".##..##.."},
		{"..##.##.."},
		{"..####..."},
		{"...###..."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
		{"...##...."},
	},
	{
		{"#########"},
		{"......###"},
		{"......##."},
		{".....###."},
		{".....##.."},
		{"....###.."},
		{"....##..."},
		{"...###..."},
		{"...##...."},
		{"..###...."},
		{"..##....."},
		{".###....."},
		{".##......"},
		{"###......"},
		{"##......."},
		{"#########"},
		{"#########"},
	}
};
bool check_num_eng(char c[20][10],int x, int y){
	for(int i = 0; i < 17; i++){
		for(int j = 0; j < 9; j++){
			if(c[i][j] != mp[x+i][y+j]) return 0;
		}
	}
	for(int i = 0; i < 17; i++){
		for(int j = 0; j < 9; j++){
			mp[x+i][y+j] = '.';
		}
	}
	return 1;
}
void find_num_eng(){
	for(int j = ny; j+8 < 500;j++){
		for(int i = nx; i+17 < 500; i++){
			for(int k = 0; k < 10; k++){
				if(check_num_eng(number[k],i,j)){
					nx = i,ny = j;
					cout << k;
					return;
				} 
			}
			for(int k = 0; k < 26; k++){
				if(check_num_eng(eng[k],i,j)){
					nx = i,ny = j;
					cout << char('A'+k);
					return;
				} 
			}			
		}
	}
	return;
}
int main(){
	freopen("recognition.in","r",stdin);
	freopen("recognition.out","w",stdout);
	for(int i = 0; i < 500; i++) cin >> mp[i];
	int t  = find_ch();
	if(t == 0) cout << "BEA9";
	if(t == 1) cout << "BDF2";
	if(t == 2) cout << "BCBD";
	if(t == 3) cout << "BDFA";
	if(t == 4) cout << "C3C9";
	if(t == 5) cout << "C1C9";
	if(t == 6) cout << "BCAA";
	if(t == 7) cout << "BADA";
	if(t == 8) cout << "BBA6";
	if(t == 9) cout << "CBD5";
	if(t == 10) cout << "D5E3";
	if(t == 11) cout << "CDEE";
	if(t == 12) cout << "C3F6";
	if(t == 13) cout << "B8D3";
	if(t == 14) cout << "C2B3";
	if(t == 15) cout << "D4A5";
	if(t == 16) cout << "B6F5";
	if(t == 17) cout << "CFE6";
	if(t == 18) cout << "D4C1";
	if(t == 19) cout << "B9F0";
	if(t == 20) cout << "C7ED";
	if(t == 21) cout << "D3E5";
	if(t == 22) cout << "B4A8";
	if(t == 23) cout << "B9F3";
	if(t == 24) cout << "D4C6";
	if(t == 25) cout << "B2D8";
	if(t == 26) cout << "C9C2";
	if(t == 27) cout << "B8CA";
	if(t == 28) cout << "C7E0";
	if(t == 29) cout << "C4FE";
	if(t == 30) cout << "D0C2";
	for(int i = 1;i <= 6; i++){
		nx = 0,ny = 0;
		find_num_eng();
	}
	return 0;
}
