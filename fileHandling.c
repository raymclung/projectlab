#define DATA_FILE "catatan.dat"

void simpanFile(){
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL){
        printf("Gagal membuka file untuk disimpan.\n");
        return;
    }

    size_t written = fwrite(data, sizeof(struct Catatan), (size_t)kapasitas, fp);
    fclose(fp);

    if (written != (size_t)kapasitas){
        printf("Gagal menulis data ke file.\n");
    } else {
        printf("Berhasil simpan %d slot catatan ke file.\n", kapasitas);
    }
}

void bukaFile(){
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL){
        printf("File belum ada atau gagal dibuka.\n");
        return;
    }

    size_t read = fread(data, sizeof(struct Catatan), (size_t)kapasitas, fp);
    fclose(fp);

    printf("Berhasil load %d catatan dari file.\n", (int)read);
}
