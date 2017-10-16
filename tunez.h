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

//array
struct song_node * add_song(struct song_node *[], char[], char[]);
struct song_node * search_lib_name(struct song_node *[], char[]);
struct song_node * search_lib_artist(struct song_node *[], char[]);
void print_lib_letter(struct song_node *[], char);
void print_lib_artist(struct song_node *[], char[]);
void print_lib(struct song_node *[]);
void print_random(struct song_node *[], int);
void delete_lib_song(struct song_node *[], char[]);
void free_lib(struct song_node *[]);
