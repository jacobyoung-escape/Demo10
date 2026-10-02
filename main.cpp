#include <iostream>     // std::cout
#include <format>       // std::format
#include <cassert>      // assert

#include "HealthPool.h"

// =============================================================================
// DEMONSTRATION 1: Stopping the program and walking through it
// =============================================================================
int ScoreForWave(int enemiesKilled, int waveNumber)
{
    int base{ enemiesKilled * 10 };
    int bonus{ waveNumber * 5 };
    int total{ base - bonus };          // WRONG on purpose: should be +

    return total;
}

void Demo01_Breakpoints()
{
    std::cout << "=== Demonstration 1: Breakpoints ===\n\n";

    int score{ ScoreForWave(4, 3) };

    std::cout << std::format("score {}\n", score);       // prints 25, should be 55

    std::cout << "\n";
}

// =============================================================================
// DEMONSTRATION 2: Looking at values while the program is stopped
// =============================================================================
void Demo02_Inspecting()
{
    std::cout << "=== Demonstration 2: Inspecting ===\n\n";

    HealthPool player{ 100 };
    HealthPool goblin{ 12 };

    HealthPool* target{ &goblin };      // Booklet 09

    player.TakeDamage(35);
    target->TakeDamage(20);             // put a breakpoint on this line

    std::cout << std::format("player {}, goblin {}\n",
        player.GetCurrent(), goblin.GetCurrent());

    std::cout << "\n";
}

// =============================================================================
// DEMONSTRATION 3: How did I get here?
// =============================================================================
int BaseScore(int enemiesKilled)
{
    return enemiesKilled * 10;          // put a breakpoint HERE
}

int WaveBonus(int waveNumber)
{
    return waveNumber * 5;
}

int TotalScore(int enemiesKilled, int waveNumber)
{
    return BaseScore(enemiesKilled) + WaveBonus(waveNumber);
}

void Demo03_CallStack()
{
    std::cout << "=== Demonstration 3: The call stack ===\n\n";

    std::cout << std::format("total {}\n", TotalScore(4, 3));

    std::cout << "\n";
}

// =============================================================================
// DEMONSTRATION 4: Conditional breakpoints
// =============================================================================
void Demo04_Conditional()
{
    std::cout << "=== Demonstration 4: Conditions ===\n\n";

    HealthPool boss{ 5000 };

    for (int turn{ 1 }; turn <= 100; ++turn)
    {
        int damage{ 500 / (turn - 47) };        // something happens on turn 47
        boss.TakeDamage(damage);
    }

    std::cout << std::format("boss ends on {}\n", boss.GetCurrent());

    std::cout << "\n";
}

// =============================================================================
// DEMONSTRATION 5: What the numbers in a crash dialog mean
// =============================================================================
void Demo05_Crashes()
{
    std::cout << "=== Demonstration 5: Crashes ===\n\n";

    HealthPool* nothing{ nullptr };

     //nothing->TakeDamage(10);
    //
    //   Exception thrown: read access violation.
    //   nothing was nullptr.

    //HealthPool* neverSet;               // <-- breakpoint on the NEXT line,
    //                                    //     then look at neverSet in Locals
    //std::cout << "stop here and read the Watch window\n";

    //neverSet->TakeDamage(10);
    ////
    ////   Exception thrown: read access violation.
    ////   neverSet was 0xCCCCCCCCCCCCCCCC.

    std::cout << "\n";
}

// =============================================================================
// DEMONSTRATION 6: Stating what must be true
// =============================================================================
int PercentageRemaining(const HealthPool& pool)
{
    assert(pool.GetMaximum() > 0 && "a health pool must have a positive maximum");

    return pool.GetCurrent() * 100 / pool.GetMaximum();
}

void Demo06_Assert()
{
    std::cout << "=== Demonstration 6: assert ===\n\n";

    HealthPool player{ 80 };
    player.TakeDamage(20);

    std::cout << std::format("{}%\n", PercentageRemaining(player));

    std::cout << "\n";
}

int main()
{
    Demo01_Breakpoints();
    //Demo02_Inspecting();
    //Demo03_CallStack();
    //Demo04_Conditional();
    //Demo05_Crashes();
    //Demo06_Assert();

    return 0;
}
