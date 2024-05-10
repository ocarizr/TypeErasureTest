
#include <chrono>
#include <cstdio>
#include <unordered_set>

#include "ITask.h"
#include "ITaskManager.h"
#include "TaskThree.h"

#include "TE_TaskManager.h"

constexpr int run = 10;

void POTest(std::vector<int> number_array)
{
	TaskOneData oneData{ 0, 1000000 };
	TaskTwoData twoData{
		"Two useful tools for UI optimization are retainer panels and invalidation panels, though both come with some caveats. Retainers collapse the entire tree into a single texture. They also support phase-based and framerate limited rendering, meaning each retainer can draw on a separate frame to avoid all the UI layout happening on the same frame. For example, you can draw your minimap on one frame and then your health bar on another frame. You can also tell retainers to render less frequently, such as rendering your minimap at 30 fps instead of 60. With phase-based rendering they can reduce draw calls by limiting redraws on the same frame. The downside to them is that they have high overhead when they rerender, so you really have to be careful. They also cost more memory since they each have their own render target. They also suffer from the same pre-4.25 problems as invalidation panels. We use them on mobile hardware, but we prefer to use invalidation panels first.The downside to invalidation panels(in 4.23) is that when one widget invalidates, the entire tree in the invalidation panel is laid out and rendered again.The downside to both is that neither work with attributes.Any core widget with a bound attribute is marked volatile, meaning it will redraw every frame.Neither work with ticking and timers either.Basically, widgets do not tick or run timers if they are in one of these panels.In 4.25 and beyond, LayoutCaching has been removed.It has been superseded by Global Invalidation, enabled via �Slate.EnableGlobalInvalidation�.Global invalidation makes it possible to remove the layout and painting overhead that Slate performs every frame across the entire UI.It also solves the need to hand place invalidation panels everywhere.Since invalidation panels have some overhead, getting the granularity right can be difficult.With global invalidation, when one widget is invalidated, it is put into a dirty list.Next frame, we evaluate how that widget changed and decide on what level of the tree layout needs to be performed.For example, when changing a color on some image brush, only that widget needs to be redrawn.When changing the size however, we may need to perform invalidation on parents since their size may be affected by their children.We do all of that automatically, resulting in a minimal set of widgets that need to be invalidated.It supports registering for tick and timers as well.Global invalidation is a very aggressive change to Slate that aims to solve the constant layout overhead of Slate once and for all.We�re still finding bugs with it, but by 4.25 it is pretty stable.We don�t turn it on by default because there are simply too many cases across all projects where widgets perform a ton of per - frame logic in a tick or paint call.Enabling those effectively disables painting and layout from getting called which would break many things that weren�t prepared for it.In Fortnite, we turn it on for the HUD only for this reason, as that�s the only perf - critical area for us.We�re also very restrictive with what goes into widgets in our HUD, going as far as writing custom tools and tests to trap ticking widgets and attributes.Again, regarding attributes, we currently have not solved that problem, so every widget with bound attributes is marked volatile and drawn every frame.It also does not solve individual widgets which are expensive(such as widgets that do a ton of logic in a tick or paint call).",
		"call"
	};

	TaskThreeData threeData{ number_array, 10 };

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < run; ++i)
	{
		PO_TaskManager manager;
		manager.start_task<TaskOneTracker, TaskOneData>(oneData);
		manager.start_task<TaskTwoTracker, TaskTwoData>(twoData);
		manager.start_task<TaskThreeTracker, TaskThreeData>(threeData);
		while (manager.has_tasks_running())
		{
			manager.tick();
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	float ms_time = time / 1000.0f;
	printf("PO Test:\n Time: %.0f us\n Average time: %.3f us", ms_time, (ms_time / static_cast<float>(run)));
}

void TETest(std::vector<int> number_array)
{
	TaskOneData oneData{ 0, 1000000 };
	TaskTwoData twoData{
		"Two useful tools for UI optimization are retainer panels and invalidation panels, though both come with some caveats. Retainers collapse the entire tree into a single texture. They also support phase-based and framerate limited rendering, meaning each retainer can draw on a separate frame to avoid all the UI layout happening on the same frame. For example, you can draw your minimap on one frame and then your health bar on another frame. You can also tell retainers to render less frequently, such as rendering your minimap at 30 fps instead of 60. With phase-based rendering they can reduce draw calls by limiting redraws on the same frame. The downside to them is that they have high overhead when they rerender, so you really have to be careful. They also cost more memory since they each have their own render target. They also suffer from the same pre-4.25 problems as invalidation panels. We use them on mobile hardware, but we prefer to use invalidation panels first.The downside to invalidation panels(in 4.23) is that when one widget invalidates, the entire tree in the invalidation panel is laid out and rendered again.The downside to both is that neither work with attributes.Any core widget with a bound attribute is marked volatile, meaning it will redraw every frame.Neither work with ticking and timers either.Basically, widgets do not tick or run timers if they are in one of these panels.In 4.25 and beyond, LayoutCaching has been removed.It has been superseded by Global Invalidation, enabled via �Slate.EnableGlobalInvalidation�.Global invalidation makes it possible to remove the layout and painting overhead that Slate performs every frame across the entire UI.It also solves the need to hand place invalidation panels everywhere.Since invalidation panels have some overhead, getting the granularity right can be difficult.With global invalidation, when one widget is invalidated, it is put into a dirty list.Next frame, we evaluate how that widget changed and decide on what level of the tree layout needs to be performed.For example, when changing a color on some image brush, only that widget needs to be redrawn.When changing the size however, we may need to perform invalidation on parents since their size may be affected by their children.We do all of that automatically, resulting in a minimal set of widgets that need to be invalidated.It supports registering for tick and timers as well.Global invalidation is a very aggressive change to Slate that aims to solve the constant layout overhead of Slate once and for all.We�re still finding bugs with it, but by 4.25 it is pretty stable.We don�t turn it on by default because there are simply too many cases across all projects where widgets perform a ton of per - frame logic in a tick or paint call.Enabling those effectively disables painting and layout from getting called which would break many things that weren�t prepared for it.In Fortnite, we turn it on for the HUD only for this reason, as that�s the only perf - critical area for us.We�re also very restrictive with what goes into widgets in our HUD, going as far as writing custom tools and tests to trap ticking widgets and attributes.Again, regarding attributes, we currently have not solved that problem, so every widget with bound attributes is marked volatile and drawn every frame.It also does not solve individual widgets which are expensive(such as widgets that do a ton of logic in a tick or paint call).",
		"call"
	};

	TaskThreeData threeData{ number_array, 10 };

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < run; ++i)
	{
		TE_TaskManager manager;
		manager.start_task<TaskOne, TaskOneData>(oneData);
		manager.start_task<TaskTwo, TaskTwoData>(twoData);
		manager.start_task<TaskThree, TaskThreeData>(threeData);
		while (manager.has_tasks_running())
		{
			manager.tick();
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	float ms_time = time / 1000.0f;
	printf("TE Test:\n Time: %.0f us\n Average time: %.3f us", ms_time, (ms_time / static_cast<float>(run)));
}

int main()
{
	std::unordered_set<int> numbers;
	numbers.insert(10);
	while (numbers.size() < 1000)
	{
		int number = rand();
		numbers.insert(number);
	}
	std::vector<int> number_array(numbers.begin(), numbers.end());

	POTest(number_array);

	printf("\n\n\n");
	TETest(number_array);

	printf("\n\n");
	return 0;
}