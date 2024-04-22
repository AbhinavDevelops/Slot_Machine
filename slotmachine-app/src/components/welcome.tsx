// Welcome.js
import React, { useEffect, useState } from 'react';
import '../welcome.css'; // Import CSS file for styling

function Welcome() {

    const [mousePosition, setMousePosition] = useState({ x: 0, y: 0 });

  useEffect(() => {
    const handleMouseMove = (e: MouseEvent) => {
      setMousePosition({ x: e.clientX, y: e.clientY });
    };

    window.addEventListener('mousemove', handleMouseMove);

    return () => {
      window.removeEventListener('mousemove', handleMouseMove);
    };
  }, []);

  const handlePlayClick = () => { console.log('Let\'s play!') };

return (
    <div className="welcome-container">
        <div className="welcome-content">
            <h1 className="welcome-title">Welcome to the Slot Machine!</h1>
            <p className="welcome-description">Feeling lucky? Place your bet and spin the reels to win big!</p>
            <button className="play-button" onClick = {handlePlayClick}>Let's Play!</button>
        </div>
        <img className="welcome-image" src="https://i.kym-cdn.com/entries/icons/original/000/049/004/lebronsunshinecover.jpg" alt="Lebron James" style={{ position: 'absolute', left: mousePosition.x, top: mousePosition.y, zIndex: -1 }} />
    </div>
);
}

export default Welcome;
