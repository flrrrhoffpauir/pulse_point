<?php

class LinkMatcher
{
  private function getLinkList() {
    $file = file_get_contents('./pulsepoint-links.txt');
    return $file;
  }

  private function loadPage($url) {
    $r = new HttpRequest($url, HttpRequest::METH_GET);
    $r->send();
    $status = $r->getResponseCode();
    return $status;
  }

  private function loadPageCURL($url) {
    $ch = curl_init();
    curl_setopt ($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt ($ch, CURLOPT_URL, $url);
    curl_setopt ($ch, CURLOPT_CONNECTTIMEOUT, 20);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($ch, CURLOPT_NOBODY, true); // HTTP request is 'HEAD'
    
    $content = curl_exec($ch);
    $info = curl_getinfo($ch);
    curl_close ($ch);
    return $info['http_code'];
  }

  public function match() {
    $fileLinks = $this->getLinkList();
    $links = array_unique(explode(PHP_EOL, $fileLinks));
    $totalLinks = count($links);
    $checkCount = 1;
    $broken = array();

    foreach ($links as $link) {
      $oldLink = $link;
      $link = str_replace('http://www.pulsepointgroup.com/', 'http://pp.smithandrobot.com/', $link);
      $status = $this->loadPageCURL($link);
      echo 'Checking '. $checkCount . ' of ' . $totalLinks .' : ' . $link . '(status: ' . $status .')' . PHP_EOL;
      if($status === 404) {
        echo 'BROKEN!!: ' . $oldLink . PHP_EOL;
        $broken[] = $link;
      }
      ++$checkCount;
    }

    if(count($broken) > 0)
    {
      echo PHP_EOL . '--- BROKEN LINKS ---' . PHP_EOL;
      foreach ($broken as $broke) {
        echo $broke . PHP_EOL;
      }
    }
  }

  public function findDuplicates() {
    $file = file_get_contents('./broken_links.txt');
    $brokenLinks = explode(PHP_EOL, $file);
    $total = count($brokenLinks);
    $after = count(array_unique($brokenLinks));
    echo 'Total 404\s = ' . $total;

  }
}

$l = new LinkMatcher();
$l->match();