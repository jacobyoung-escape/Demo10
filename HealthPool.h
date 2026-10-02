#ifndef HEALTHPOOL_H
#define HEALTHPOOL_H

// =============================================================================
// The type used by the whole booklet. You met it in Booklet 08 Demonstration 6.
// =============================================================================
class HealthPool
{
public:
    HealthPool() = default;

    HealthPool(int maximum)
        : currentHealth(maximum), maximumHealth(maximum)
    {
    }

    int GetCurrent() const { return currentHealth; }
    int GetMaximum() const { return maximumHealth; }
    bool IsAlive() const { return currentHealth > 0; }

    float Fraction() const
    {
        return static_cast<float>(currentHealth) / maximumHealth;
    }

    void TakeDamage(int amount)
    {
        currentHealth -= amount;

        if (currentHealth < 0)
        {
            currentHealth = 0;
        }
    }

    void Heal(int amount)
    {
        currentHealth += amount;

        if (currentHealth > maximumHealth)
        {
            currentHealth = maximumHealth;
        }
    }

private:
    int currentHealth{ 0 };
    int maximumHealth{ 1 };
};

#endif // HEALTHPOOL_H
