#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

#define MAX_SPOTS   4

struct Spot {
    vec2 pos;        // window coords of spot
    float inner;    // inner fully transparent centre radius
    float radius;    // alpha fades out to this radius
};
uniform int spotNb;
uniform Spot spots[MAX_SPOTS];      // Spotlight positions array
uniform float screenWidth;          // Width of the screen
uniform float screenHeight;          // Height of the screen

void main()
{
    if (spotNb == 0) {
       finalColor = vec4(0, 0, 0, 0.3);
       return; 
    }
    float alpha = 0.3;

    // Get the position of the current fragment (screen coordinates!)
    vec2 pos = vec2(gl_FragCoord.x,  screenHeight - gl_FragCoord.y);

    // Find out which spotlight is nearest
    float d = 650000;  // some high value
    int fi = -1;      // found index

    for (int i = 0; i < spotNb; i++)
    {
        for (int j = 0; j < spotNb; j++)
        {
            float dj = distance(pos, spots[j].pos) - spots[j].radius + spots[i].radius;

            if (d > dj)
            {
                d = dj;
                fi = i;
            }
        }
    }

    // d now equals distance to nearest spot...
    // allowing for the different radii of all spotlights
    if (fi != -1)
    {
        if (d >= spots[fi].radius) alpha = 0.3;
        else
        {
            if (d < spots[fi].inner) alpha = 0.0f;
            else alpha = 0.3 * (d - spots[fi].inner) / (spots[fi].radius - spots[fi].inner);
        }
    }

    // Right hand side of screen is dimly lit,
    // could make the threshold value user definable
    // if ((pos.x > screenWidth/2.0) && (alpha > 0.9)) alpha = 0.9;
    // alpha = 1.2;

    finalColor = vec4(0, 0, 0, alpha);
}
