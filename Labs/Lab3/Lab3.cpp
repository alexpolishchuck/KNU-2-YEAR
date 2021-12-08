    #include <iostream>
    #include <stdio.h>
    #include <time.h>
    #include <SFML/Graphics.hpp>
    #include <chrono>


    #pragma comment(lib,"sfml-graphics-d.lib")
    #pragma comment(lib,"sfml-window-d.lib")
    #pragma comment(lib,"sfml-system-d.lib")
    #pragma comment(lib,"sfml-audio-d.lib")
    #pragma comment(lib,"sfml-network-d.lib")

    using std::cin; 
    using std::cout;
    using std::endl;
    using namespace sf;

    const int length = 18;
    const int width = 10;
    int field[length][width] = { 0 };

    struct point
    {
        int x;
        int y;

    }a[4], b[4];

    int figures[7][4]
    {
        
        0,2,4,6,
        0,2,3,5,
        1,3,2,4,
        1,3,2,5,
        0,1,3,5,
        1,3,5,4,
        0,1,2,3,

    };

    bool check()
    {
        for (int i = 0; i < 4; i++)
            if (b[i].x < 0 || b[i].x >= width || b[i].y >= length || field[b[i].y][b[i].x])
                return false;

        return true;
    }

    bool checkY()
    {
        for (int i = 0; i < 4; i++)
            if (a[i].y + 1 >= length || field[a[i].y + 1][a[i].x])
                return false;

        return true;
    }

    void checkline(int* score)
    {
        int k = length - 1;
        bool answer = true;
        for (int i = length - 1; i > 0; i--)
        {
            answer = true;

            for (int j = 0; j < width; j++)
            {
                if (field[i][j] == 0)
                    answer = false;

                field[k][j] = field[i][j];
            }
            if (answer == false)
                k--;
            else
                *score += 10;

        }

    }

    void hardDrop()
    {
        if (checkY())
        {
            for (int i = 0; i < 4; i++)
                a[i].y++;
        }
        else return;

    }

    void createNewFigure(int n)
    {
        int koef1 = -1;
        int koef2 = 3;
        for (int i = 0; i < 4; i++)
        {
            a[i].x = figures[n][i] / 2 + koef2;
            a[i].y = figures[n][i] % 2 + koef1;
        }
    }


    void DrawWindow(int FRAME_DURATION, unsigned lag, int timer, int* score, Sprite sprite, RenderWindow* window, int colornum,bool isgameended,Sprite oldfigsprite)
    {

        if (FRAME_DURATION > lag)
        {
            //InformationTab
            RectangleShape InformationTab(Vector2f(5 * 36, 5 * 36));
            InformationTab.setFillColor(sf::Color(0, 0, 0));
            InformationTab.setOutlineThickness(-1);
            InformationTab.setPosition(36 * (1.5f * width - 2.5f), 36 * (0.25f * length - 2.5f));

            //text inside table
            Text text;
            Font font;
            font.loadFromFile("sansation.ttf");
            text.setPosition(36 * (1.5 * width - 2.5f) + 5, 36 * (0.25f * length - 2.5f));
            text.setString("Time: " + std::to_string(timer) + "\nScore: " + std::to_string(*score));
            text.setOutlineColor(Color::White);
            text.setCharacterSize(18);
            text.setFont(font);
            text.setStyle(Text::Bold);

            //End of game text
            Text endOfGame;

            endOfGame.setString("YOUR SCORE: " + std::to_string(*score));
            endOfGame.setCharacterSize(36);
            endOfGame.setFont(font);
            endOfGame.setStyle(Text::Bold);
            endOfGame.setFillColor(Color::White);
            endOfGame.setPosition(200, 325);
            //EndOfGame Rect

           // RectangleShape EndOfGameTab(endOfGame.getScale());
            RectangleShape EndOfGameTab(Vector2f(endOfGame.getLocalBounds().width, endOfGame.getLocalBounds().height * 2));
            EndOfGameTab.setFillColor(sf::Color(0, 0, 0));
            EndOfGameTab.setOutlineThickness(-1);
            EndOfGameTab.setPosition(200, 325);




            RectangleShape cell(sf::Vector2f(35, 35));              //added 25.11.21

            //SET COLOUR for the current figure//
            sprite.setTextureRect(IntRect(colornum * 36, 0, 36, 36));

            (*window).clear(Color::Black);

       

            /*for (int i = 0; i < 4; i++)
            {

                sprite.setPosition(a[i].x * 36, a[i].y * 36);
                sprite.move(36, 36);
                window.draw(sprite);
            }*/

            //CHECK LINE//
            checkline(score);
            if (isgameended)
            {
                (*window).draw(EndOfGameTab);
                (*window).draw(endOfGame);
            }
            else
            {

                for (int i = 0; i < length; i++)
                    for (int j = 0; j < width; j++)
                    {
                        if (field[i][j] == 0)
                        {
                            cell.setPosition(static_cast<float>(36 * j + 36), static_cast<float>(36 * i + 36));     //added 25.11.21
                            cell.setFillColor(Color::Yellow);
                            (*window).draw(cell);

                            continue;
                        }
                        //SET COLOUR for other figures//
                        oldfigsprite.setTextureRect(IntRect(field[i][j] * 36, 0, 36, 36));
                        oldfigsprite.setPosition(j * 36, i * 36);
                        oldfigsprite.move(36, 36);
                        (*window).draw(oldfigsprite);
                    }

                //new figure
                for (int i = 0; i < 4; i++)
                {

                    sprite.setPosition(a[i].x * 36, a[i].y * 36);
                    sprite.move(36, 36);
                    (*window).draw(sprite);
                }

                (*window).draw(InformationTab);
                (*window).draw(text);
            }
            (*window).display();
            /*if (isgameended)
                break;*/
        }
    }

    int main()
    {
        srand(time(NULL));
        RenderWindow window(VideoMode(650, 750), "Sasha's Tetris", Style::Close);
        window.setView(View(FloatRect(0, 0, 650, 750)));
        Texture texture, bgtexture;
        texture.loadFromFile("newtexturesforgame-1.png");
        Sprite sprite(texture), oldfigsprite(texture);
        sprite.setTextureRect(IntRect(0, 0, 36, 36));

        int dx = 0;
        int rotate = 0;
        
        int timer = 0, score = 0;
        //game mode
        bool isgamestarted = true;
        bool isgameended = false;
        //random color
        int colornum = 1 + rand() % 6;
        //random number
        int n;
        //Fall parameters
        int FallSpeed = 412340 * 2;
        int FallTimer = 0;
        //int koef = -1;


        unsigned lag = 0;

        std::chrono::time_point<std::chrono::steady_clock> previous_time;       //added 24.11.2021
        previous_time = std::chrono::steady_clock::now();
        int FRAME_DURATION = 16667 * 3;     //*7
        int increaseSpeed = 0;
        // window.setKeyRepeatEnabled(false);

         //game session time
        Clock clock;
        Event event;
    
    

        while (window.isOpen() /*&& !isgameended*/)
        {
            unsigned delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();
            lag += delta_time;
            previous_time += std::chrono::microseconds(delta_time);
            FallTimer++;

        

            /// we get time elapsed since the beginning/restart///

            timer = clock.getElapsedTime().asSeconds();
            // clock.restart();
            // timer += time;




            while (FRAME_DURATION <= lag)
            {
                lag -= FRAME_DURATION;
                dx = 0;                              //delete

                while (window.pollEvent(event))
                {

                    if (event.type == Event::Closed)
                        window.close();
                    if (event.type == Event::KeyPressed && !isgameended)
                    {
                        if (event.key.code == Keyboard::D)
                            dx += 1;                             //++
                        else if (event.key.code == Keyboard::A)
                            dx += -1;                              //--
                        else if (event.key.code == Keyboard::W)
                            rotate = 1;
                        else if (event.key.code == Keyboard::S)
                            rotate = -1;
                        else if (Keyboard::isKeyPressed(Keyboard::Down)) //delay = realdelay / 10;
                            increaseSpeed = 1;
                    }
                        else 
                            if (isgameended && event.type == Event::KeyPressed && event.key.code == Keyboard::R)
                            {


                                for (int i = 0; i < length; i++)
                                    for (int j = 0; j < width; j++)
                                    {
                                        field[i][j] = 0;
                                    }
                                lag = 0;
                                timer = 0;
                                clock.restart();
                                increaseSpeed = 0;
                                FallTimer = 0;
                                colornum = 1 + rand() % 6;
                                isgamestarted = true;
                                isgameended = false;
                                dx = 0;
                                rotate = 0;
                                score = 0;



                            }
                }

                ///MOVE <->///
           

                if (dx)
                {

                    for (int i = 0; i < 4; i++)
                    {
                        if (a[i].x + dx >= width || a[i].y >= length || a[i].y < 0 || a[i].x + dx < 0 || field[a[i].y][a[i].x + dx])
                            break;
                        if (i == 3)
                            for (int k = 0; k < 4; k++)
                                a[k].x += dx;


                    }

                }


                ///rotate left///
                if (rotate)
                {
                    if (rotate > 0)
                        for (int i = 0; i < 4; i++)
                        {
                            b[i] = a[i];
                            int x;
                            int y;

                            point temporary = a[1];
                            x = 0 - b[i].y + temporary.y;
                            y = b[i].x - temporary.x;
                            b[i].x = x + temporary.x;
                            b[i].y = y + temporary.y;

                        }
                    else if (rotate < 0)
                        for (int i = 0; i < 4; i++)
                        {
                            b[i] = a[i];
                            int x;
                            int y;
                            point temporary = a[1];
                            x = b[i].y - temporary.y;
                            y = 0 - b[i].x + temporary.x;
                            b[i].x = x + temporary.x;
                            b[i].y = y + temporary.y;
                        }
                    if (check())
                        for (int i = 0; i < 4; i++)
                            a[i] = b[i];
                }

                ///DROP HARD ///

                if (increaseSpeed)
                    hardDrop();



                //// TICK////


                if (FallTimer >= FallSpeed) 
                {
                    FallTimer = 0;


                    if (checkY())
                        for (int i = 0; i < 4; i++)
                            a[i].y++;
                    else
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            field[a[i].y][a[i].x] = colornum;

                        }
                        colornum = 1 + rand() % 6;
                        n = rand() % 7;
                        createNewFigure(n);
                    }

                }

                if (!checkY())
                    for (int i = 0; i < 4; i++)             //if touching anything
                    {
                        if (a[i].y == 0)
                            isgameended = true;
                        cout << isgameended << endl;
                    }



                if (isgamestarted)
                {
                    n = rand() % 7;

                    createNewFigure(n);

                    isgamestarted = false;
                }

                dx = 0;
                rotate = 0;
                increaseSpeed = 0;             //delete
              

                // DRAW // 
                DrawWindow(FRAME_DURATION, lag, timer, &score, sprite, &window, colornum, isgameended, oldfigsprite);

            }

        }
        system("pause");
        return 0;
    }