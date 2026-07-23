use std::cmp::Reverse;
use std::collections::BinaryHeap;

const INF: i64 = i64::MAX / 4;

fn dijkstra(s: usize, dist: &mut [i64], parent: &mut [Option<usize>], adj: &[Vec<(usize, i64)>]) {
    dist.fill(INF);
    parent.fill(None);

    let mut heap = BinaryHeap::new();

    dist[s] = 0;
    heap.push(Reverse((0_i64, s)));

    while let Some(Reverse((current_dist, v))) = heap.pop() {
        if current_dist != dist[v] {
            continue;
        }

        for &(to, weight) in &adj[v] {
            let new_dist = current_dist + weight;

            if new_dist < dist[to] {
                dist[to] = new_dist;
                parent[to] = Some(v);
                heap.push(Reverse((new_dist, to)));
            }
        }
    }
}

fn restore_path(s: usize, t: usize, parent: &[Option<usize>]) -> Option<Vec<usize>> {
    let mut path = vec![];
    let mut v = t;

    while v != s {
        path.push(v);
        v = parent[v]?;
    }

    path.push(s);
    path.reverse();

    Some(path)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn add_directed_edge(adj: &mut [Vec<(usize, i64)>], from: usize, to: usize, weight: i64) {
        adj[from].push((to, weight));
    }

    #[test]
    fn finds_shortest_distances_and_restores_path() {
        let mut adj = vec![vec![]; 5];
        add_directed_edge(&mut adj, 0, 1, 10);
        add_directed_edge(&mut adj, 0, 2, 3);
        add_directed_edge(&mut adj, 2, 1, 1);
        add_directed_edge(&mut adj, 1, 3, 2);
        add_directed_edge(&mut adj, 2, 3, 8);
        add_directed_edge(&mut adj, 3, 4, 4);

        let mut dist = vec![INF; adj.len()];
        let mut parent = vec![None; adj.len()];

        dijkstra(0, &mut dist, &mut parent, &adj);

        assert_eq!(dist, vec![0, 4, 3, 6, 10]);
        assert_eq!(restore_path(0, 4, &parent), Some(vec![0, 2, 1, 3, 4]));
    }

    #[test]
    fn leaves_unreachable_vertices_at_infinity() {
        let mut adj = vec![vec![]; 4];
        add_directed_edge(&mut adj, 0, 1, 5);
        add_directed_edge(&mut adj, 2, 3, 1);

        let mut dist = vec![0; adj.len()];
        let mut parent = vec![Some(0); adj.len()];

        dijkstra(0, &mut dist, &mut parent, &adj);

        assert_eq!(dist, vec![0, 5, INF, INF]);
        assert_eq!(restore_path(0, 3, &parent), None);
    }

    #[test]
    fn ignores_stale_heap_entries_after_a_better_route_is_found() {
        let mut adj = vec![vec![]; 4];
        add_directed_edge(&mut adj, 0, 1, 100);
        add_directed_edge(&mut adj, 0, 2, 1);
        add_directed_edge(&mut adj, 2, 1, 1);
        add_directed_edge(&mut adj, 1, 3, 1);
        add_directed_edge(&mut adj, 2, 3, 50);

        let mut dist = vec![INF; adj.len()];
        let mut parent = vec![None; adj.len()];

        dijkstra(0, &mut dist, &mut parent, &adj);

        assert_eq!(dist, vec![0, 2, 1, 3]);
        assert_eq!(restore_path(0, 3, &parent), Some(vec![0, 2, 1, 3]));
    }

    #[test]
    fn resets_output_buffers_and_handles_source_path() {
        let mut adj = vec![vec![]; 3];
        add_directed_edge(&mut adj, 2, 1, 7);

        let mut dist = vec![123; adj.len()];
        let mut parent = vec![Some(2); adj.len()];

        dijkstra(2, &mut dist, &mut parent, &adj);

        assert_eq!(dist, vec![INF, 7, 0]);
        assert_eq!(parent, vec![None, Some(2), None]);
        assert_eq!(restore_path(2, 2, &parent), Some(vec![2]));
    }
}
