
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
