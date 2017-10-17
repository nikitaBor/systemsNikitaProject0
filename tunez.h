struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

//list
void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *, char[], char[]);
struct song_node * insert_alph(struct song_node *, char[], char[]);
struct song_node * search_list_name(struct song_node *, char[]);
struct song_node * search_list_artist(struct song_node *, char[]);
struct song_node * search_list_random(struct song_node *);
void delete_list_song(struct song_node *, char[]);
void free_list(struct song_node *);


