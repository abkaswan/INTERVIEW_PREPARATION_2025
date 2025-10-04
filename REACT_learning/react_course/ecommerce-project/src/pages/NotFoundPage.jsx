import './NotFoundPage.css';
import { Header } from '../components/Header';
export function NotFoundPage() {
  return (
    <>
        <title>404 Not Found</title>
        <link rel="icon" type="image/svg+xml" href="images/home-favicon.png" />
        <Header />
        <div className="not-found-page">
          <div className="not-found-page-content">
            <div className="not-found-page-title">404</div>
            <div className="not-found-page-subtitle">Page Not Found</div>
          </div>
        </div>
    </>
  );
}