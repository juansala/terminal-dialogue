# Game Class

- For now, include assets in headers
- Try making a Screen class, a generic base class for
    - Menus
    - End Screens
    - Animations/Dialogue
    - Maps
    - Think: A Screen will behave like a state machine...options or no
    - Supports:
        - Internal state
        - update(bool input) function that renews the shown menu screen
            - Uses boolean input to determine whether it needs to update the screen
            - Will run in main Game loop, needs to be instantiated at Game start
- Make a Menu class that supports the following:
    