struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *);
struct song_node * insert_alph(struct song_node *);
struct song_node * find_by_name(struct song_node*);
struct song_node * find_by_artist(struct song_node*);
struct song_node * find_random(struct song_node*);
