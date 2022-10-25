enum colour {
    WHITE,
    RED,
    YELLOW,
    LIME,
    CYAN,
    BLUE,
    MAGENTA,
    BLACK
};

struct rgb {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct rgb make_rgb (enum colour c) {
    struct rgb c_rgb;
    switch (c)
    {
    case WHITE:
    {
        c_rgb.r = '53';
        c_rgb.g = '53';
        c_rgb.b = '53';
        return  c_rgb;
    }
    case RED:
    {
        c_rgb.r = '53';
        c_rgb.g = '48';
        c_rgb.b = '48';
        return  c_rgb;
    }
    case YELLOW:
    {
        c_rgb.r = '53';
        c_rgb.g = '53';
        c_rgb.b = '48';
        return  c_rgb;
    }
    case LIME:
    {
        c_rgb.r = '48';
        c_rgb.g = '53';
        c_rgb.b = '48';
        return  c_rgb;
    }
    case CYAN:
    {
        c_rgb.r = '48';
        c_rgb.g = '53';
        c_rgb.b = '53';
        return  c_rgb;
    }
    case BLUE:
    {
        c_rgb.r = '48';
        c_rgb.g = '48';
        c_rgb.b = '53';
        return  c_rgb;
    }
    case MAGENTA:
    {
        c_rgb.r = '53';
        c_rgb.g = '48';
        c_rgb.b = '53';
        return  c_rgb;
    }
    case BLACK:
    {
        c_rgb.r = '48';
        c_rgb.g = '48';
        c_rgb.b = '48';
        return  c_rgb;
    }
    default:
        c_rgb.r = '0';
        c_rgb.g = '0';
        c_rgb.b = '0';
        return  c_rgb;
    }
}