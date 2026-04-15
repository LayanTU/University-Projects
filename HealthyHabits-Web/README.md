# 🥗 Healthy Habits Web Concept

A multi-page static HTML frontend project designed to promote healthy living, dietary balance, and daily wellness routines. 

This project was developed as a collaborative university assignment to solidify core **Web Architecture** concepts and understand the fundamental building blocks of client-side rendering.

## 📌 Tech Stack
* **Language:** HTML5
* **Concepts:** Client-Side Architecture, Document Object Model (DOM), Semantic HTML, Local Navigation

## 📌 Security & Architecture Highlights

As an aspiring Application Security Engineer, building foundational web structures is important to help in understanding how web apps are built in order to break them safely. This project provided practical experience with the client-side technologies that are frequently targeted in web exploitation:

* **DOM Structure Mapping:** Engineered a semantic HTML document structure using tags like `<header>`, `<main>` and `<section>`. Mastering how the Document Object Model parses these elements is essential for identifying and exploiting future DOM-based Cross-Site Scripting (XSS) vulnerabilities.
* **Client-Side Routing Logic:** Implemented interconnected local page navigation. Analyzing how static pages link together establishes a baseline for understanding web flow, which is necessary when hunting for Broken Access Control or mapping an application's attack surface.
* **Inline Resource Handling:** Utilized inline styling and local image rendering. From an offensive security perspective, understanding how browsers parse inline CSS and external media attributes is crucial for crafting payload contexts and bypassing basic input filters.
* **Input Surface Awareness:** While static, structuring the layout highlights where dynamic inputs (like contact forms or comment sections) would typically integrate into the DOM tree, marking future areas of interest for security testing.

## 📌 System Structure

The application is structured into interconnected, static HTML files to separate content domains:
* `Home.html`: The core landing page, primary navigation hub, and project introduction. **(Developed by me)**
* `eating.html`: Nutritional advice, daily eating tips, and dietary philosophy.
* `habits.html`: Core principles of daily habit formation and consistency.
* `lifestyle.html`: Quick, actionable lifestyle adjustments for overall wellness.
* `banner.jpeg` & `image1.jpg`: Local media assets rendered within the DOM.

## 📌 How to Run
1. Clone the repository to your local machine using the terminal (`git clone https://github.com/LayanTU/University-Projects/`).
2. Navigate to the project folder.
3. Open the `Home.html` file directly in any modern web browser (Chrome, Firefox, Edge).
4. Use the navigation links at the top of the page to explore the connected files.
